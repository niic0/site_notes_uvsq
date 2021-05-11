#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define DICT_NAME_MAX 64

/* entry of a dictionary, consists in a name and its value */
struct dictionary_item {
    char name[DICT_NAME_MAX];
    double value;
};

/* operators of a dictionary */
enum command_op {
    OP_ADD,     /* add an entry */
    OP_REMOVE,  /* remove an entry */
    OP_ASK,     /* ask about an entry */
    OP_EXIT     /* terminate server */
};

/* command extracted from the input pipe */
struct command {
    enum command_op op;
    char name[DICT_NAME_MAX];
    double value;  
};

/* allocate the dictionary structure */
int
create_dict(const char *size_string, struct dictionary_item **dict,
            size_t *dict_max_size)
{
    for (int i=0; i<atoi(size_string) ; i++ )
        dict[i] = malloc(sizeof(struct dictionary_item));

    if (dict == NULL) {
        perror("[ERR] Malloc error");
        return 1;
    }

    return 0;
}

/* free the dictionary structure */
void
destroy_dict(struct dictionary_item *dict)
{
    free(dict);
}

/* create the pipe files used by the server */
int
create_pipes(const char *dict_name)
{
    char buf[256];
    sprintf(buf, "/tmp/dict_%s", dict_name);

    if(mkfifo(buf, 0666) == -1) {
        perror("[ERR] Error on mkfifo function ");
        return 1;
    }
    return 0;
}

/* destroy the pipe files used by the server */
void
destroy_pipes(const char *dict_name)
{
    char buf[256];

    sprintf(buf, "/tmp/dict_%s", dict_name);
    unlink(buf);
}

/* open a pipe for the given dictionary, input or output side */
int
open_pipe(const char *dict_name, bool dict_input)
{
    char buf[256];

    sprintf(buf, "/tmp/dict_%s", dict_name);
    return open(buf, dict_input ? O_RDONLY : O_WRONLY);
}

/* close a pipe */
void
close_pipe(int fd)
{ close(fd); }

/* receive a command from the input pipe */
int
receive_command(int fd, struct command *cmd)
{
    char buf[1024];
    if (read(fd, buf, 256) == -1){
        perror("[ERR] read error");
        return 1;
    }

    if(buf[0] == '!'){
        cmd->op = OP_EXIT;
    }
    if(buf[0] == '+'){
        char * endPtr;
        double value = strtod(buf, &endPtr);

        cmd->op = OP_ADD;
        cmd->value = value;
        strcpy(cmd->name,endPtr);
    }
    if (buf[0] == '?') {
        cmd->op = OP_ASK;
        char bufName[256] = "\0";
        long unsigned int i = 1;
        int j=0;

        while(i < strlen(buf)){
            bufName[j]=buf[i];
            j++;
            i++;
        }
        strcpy(cmd->name,bufName);
    }
    if (buf[0] == '-') {
        cmd->op = OP_REMOVE;
        char bufName[256] = "\0";
        long unsigned int i = 1;
        int j=0;

        while(i < strlen(buf)){
            bufName[j]=buf[i];
            j++;
            i++;
        }
        strcpy(cmd->name,bufName);
    }

    return 0;
}

/* add an entry to the dictionary */
int
dict_add(struct dictionary_item *dict, int *dict_count,
         size_t dict_max_size, struct command cmd)
{
    dict[*dict_count].value = cmd.value;
    strcpy(dict[*dict_count].name,cmd.name);

    *dict_count=*dict_count+1;
    return 1;
}

/* remove an entry from the dictionary */
int
dict_remove(struct dictionary_item *dict, int *dict_count,
            struct command cmd)
{
    int i = 0;
    while(strcmp(cmd.name, dict[i].name)){
        i++;
        if (i == *dict_count){
            printf("[INF] Didn't find %s\n", cmd.name);
            return 1;
        }
    }

    for(i=i; i<*dict_count-1; i++)
        dict[i] = dict[i+1];

    *dict_count = *dict_count -1;

    return 0;
}

/* ask the value of a dictionary entry, if exists */
int
dict_ask(struct dictionary_item *dict, int dict_count, struct command *cmd)
{
    int i = 0;

    while(strcmp(cmd->name,dict[i].name)){
        i++;
        if (i == dict_count){
            printf("[INF] Didn't find %s\n", cmd->name);
            strcpy(cmd->name, "NOT FOUND");
            return 1;
        }
    }
    cmd->value = dict[i].value;
    return 0;
}

/* send the response of an ask request */
int
send_response(int fd, int error, struct command cmd)
{
    if (!strcmp(cmd.name,"NOT FOUND")){
        if(write(fd, "NOT FOUND", 254) == -1){
            error = 1;
            return 1;
        }
    }
    else {
        char buf[256];
        snprintf(buf,256,"%f",cmd.value);
        if(write(fd, buf, 254) == -1){
            error = 1;
            return 1;
        }
    }

    return 0;
}

/* main function, contains the server loop */
int
main(int argc, char **argv)
{
    struct dictionary_item *dict;
    int dict_count = 0;
    size_t dict_max_size;
    bool done = false;
    int fd[2] = { -1, -1 };
    int rc;
//    char c;

    if (argc != 3) {
        fprintf(stderr,
                "[ERR] usage: %s name size\n"
                "             name -- dictionary name\n"
                "             size -- maximum dictionary size\n",
                argv[0]);
        rc = 1;
        goto err_exit;
    }

    rc = create_dict(argv[2], &dict, &dict_max_size);

   if (rc)
        goto err_exit;


    rc = create_pipes(argv[1]);
    if (rc)
        goto err_dict;

    do {
        struct command cmd;
        int rc2;

        fd[0] = open_pipe(argv[1], true);
        if (fd[0] < 0) {
            perror("[ERR] pipe error");
            rc = 1;
            goto err_pipe;
        }

        rc = receive_command(fd[0], &cmd);
        if (rc)
            break;

        switch(cmd.op) {
        case OP_ADD:
            rc2 = dict_add(dict, &dict_count, dict_max_size, cmd);

            break;
        case OP_REMOVE:
            rc2 = dict_remove(dict, &dict_count, cmd);
            break;
        case OP_ASK:
            fd[1] = open_pipe(argv[1], false);
            rc2 = dict_ask(dict, dict_count, &cmd);
            if (fd[1] < 0) {
                perror("pipe error");
                rc = 1;
                goto err_pipe;
            }
            rc = send_response(fd[1], rc2, cmd);
            close_pipe(fd[1]);
            break;
        case OP_EXIT:
            fprintf(stderr, "[INF] will quit\n");
            done = true;
        };

        if (rc)
            break;

        close_pipe(fd[0]);
    } while(!done);

err_pipe:
    close_pipe(fd[0]);
    destroy_pipes(argv[1]);

err_dict:
    destroy_dict(dict);

err_exit:
    return rc;
}
