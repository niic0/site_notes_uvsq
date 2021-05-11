#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/* print usage message and return nonnull rc */
int
usage(const char *prog)
{
    fprintf(stderr,
            "[ERR] usage: %s dict action [opt1 opt2]\n"
            "             action: + name value\n"
            "                     - name\n"
            "                     ? name\n"
            "                     !\n",
            prog);

    return 1;
}

/* print error message on stderr and return nonnull rc */
int
log_error(const char *msg)
{
    fprintf(stderr, "[ERR] %s\n", msg);
    return 1;
}

/* open a pipe for the given dictionary, input or output side */
int
open_pipe(const char *dict_name, bool dict_input)
{
    char buf[256];

    sprintf(buf, "/tmp/dict_%s", dict_name);
    return open(buf, dict_input ? O_RDONLY : O_WRONLY);
}

/* TODO: send add command to the server */
int
dict_add(const char *dict_name, const char *value_name, double value)
{
    int fd = open_pipe(dict_name, false);
    char buf[256];

    snprintf(buf,256,"%f",value);

    if(write(fd, "+", sizeof(char)) == -1){
        perror("[ERR] on writing in pipe");
        return 1;
    }
    if (write(fd, buf , sizeof(value)) == -1){
        perror("[ERR] on writing in pipe");
        return 1;
    }
    if (write(fd, value_name, sizeof(value_name)) == -1){
        perror("[ERR] on writing in pipe");
        return 1;
    }

    close(fd);

    printf("Adding %s -> %f\n",value_name, value);

    return 0;
}

/* TODO: send remove commant to the server */
int
dict_remove(const char *dict_name, const char *value_name)
{
    int fd = open_pipe(dict_name,false);

    if(write(fd, "-", sizeof(char)) == -1){
        perror("[ERR] on writing in pipe");
        return 1;
    }
    if (write(fd, value_name , sizeof(value_name)) == -1){
        perror("[ERR] on writing in pipe");
        return 1;
    }

    printf("Removing %s\n", value_name);

    close(fd);

    return 1;
}

/* TODO: send ask command to the server */
int
dict_ask(const char *dict_name, const char *value_name)
{
    int fd = open_pipe(dict_name, false);

    if(write(fd, "?", sizeof(char)) == -1){
        perror("[ERR] on writing in pipe");
        return 1;
    }
    if (write(fd,value_name,128*sizeof(char)) == -1){
        perror("[ERR] on writing in pipe");
        return 1;
    }

    close(fd);
    char buf[1024];

    fd = open_pipe(dict_name,true);
    if (read(fd, buf, 256) == -1){
        perror("read error");
        return 1;
    }
    if(!strcmp(buf,""))
        printf("No result for %s",value_name);
    else
        printf("Value of %s : %s\n",value_name,buf);

    close(fd);
    return 0;
}

/* TODO: send exit command to the server */
int
dict_exit(const char *dict_name)
{
    int fd = open_pipe(dict_name, false);

    puts("Sending exit message to the server...");
    if(write(fd,"!", sizeof("!")) == -1){
        perror("[ERR] on writing in pipe");
    }

    return 1;
}

/* client main function, literally parse the program args
 * and then send the command to the desired server */
int
main(int argc, char **argv)
{
    if (argc < 3)
        return usage(argv[0]);

    if (strcmp(argv[2], "+") == 0) {
        if (argc != 5)
            return usage(argv[0]);

        return dict_add(argv[1], argv[3], atof(argv[4]));
    } else if (strcmp(argv[2], "-") == 0) {
        if (argc != 4)
            return usage(argv[0]);

        return dict_remove(argv[1], argv[3]);
    } else if (strcmp(argv[2], "?") == 0) {
        if (argc != 4)
            return usage(argv[0]);

        return dict_ask(argv[1], argv[3]);
    } else if (strcmp(argv[2], "!") == 0) {
        if (argc != 3)
            return usage(argv[0]);

        return dict_exit(argv[1]);
    }

    return usage(argv[0]);
}
