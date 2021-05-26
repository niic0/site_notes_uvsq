#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <ctype.h>

/*
 * contain arguments we need for the function print_occ_mTh
*/
typedef struct args{
  char* strToFind;
  char* txt;
  int nbrTh;
  size_t start;
  size_t end;
}args;


size_t size_file(const char* path);             // return the size of <path>
int get_txt(const char* path, char** buf_str);  // transform text file in string
int print_occ_seq(char* path, char* strToFind); // print occurence of a string
void* print_occ_mTh(void* argsPnt);             // print occurence of a string (multi thread)
void free_all(args* args);                       // free memory
int usage(int argc, char** argv);               // check if arguments are correct



int main(int argc, char** argv){
  if(usage(argc, argv)) return 1;

  int nbrTh = atoi(argv[1]);        // number of threads
  pthread_t threads[nbrTh];         // variable that will start different threads
  args args[nbrTh];                 // contain all variables needed by print_occ_mTh
  int ret;                          // ret !=0 if pthread_create return an error

  for(int i=0; i<nbrTh; i++){
    get_txt(argv[3], &args[i].txt);
    args[i].strToFind = argv[2];

    args[i].start = i*((int)size_file(argv[3]))/nbrTh;   // set the start of the reading head

    if (nbrTh == 1) args[i].end = size_file(argv[3]);    // set the end of the reading head
    else args[i].end = (i+1)*((int)size_file(argv[3]))/nbrTh;

    ret = pthread_create(&threads[i], NULL, print_occ_mTh, (void*)&args[i]);
    if(ret) fprintf(stderr, "%s\n", strerror(ret));
  }

  for (int i = 0; i<nbrTh; i++) ret = pthread_join(threads[i], NULL); // waiting all threads
  if(ret) fprintf(stderr, "%s\n", strerror(ret));

  free_all(args);
  return 0;
}


/*
 * print the occurence with threads
 * ARG : the struct that contain what we need (text, start, start, end, the word to find and
 *                                             the number of threads)
 * RET : nothing
*/
void* print_occ_mTh(void* argsPnt){
  args *args = argsPnt;

  for(size_t i=args->start; i<args->end; i++){
    if(args->strToFind[0] == args->txt[i]){
      size_t k=1;
      while(args->strToFind[k] == args->txt[i+k]){
        k++;
        if(k == strlen(args->strToFind)) fprintf(stdout,"%zu\n", i);
      }
    }
  }
  return NULL;
}


/*
 * print occurence of a word sequentially
 * ARGS : <path> point to the file where we are searching the word
 * RET  : 0 on success, 1 if fail
*/
int print_occ_seq(char* path, char* strToFind){
  char* txt;
  if(get_txt(path, &txt)) return 1;
  size_t lenght = size_file(path);

  for(size_t i=0; i<lenght; i++){
    if(strToFind[0] == txt[i]){
      size_t k=1;
      while(strToFind[k] == txt[i+k]){
        k++;
        if(k == strlen(strToFind)) fprintf(stdout,"%zu\n", i);
      }
    }
  }

  return 0;
}


/*
 * return the size of the file pointed by <path>
*/
size_t size_file(const char* path){
  int fd = open(path, O_RDONLY);
  if(fd == -1){
    fprintf(stderr, "%s\n", strerror(errno));
    exit(1);
  }
  int lenght = lseek(fd, 0, SEEK_END); // position of the last char = size of the file
  close(fd);
  return lenght;
}


/*
 * put the content of a file in a string
 * ARGS : - <path> point to the path of the file
 *        - <buf_str> point to the string that will contain the content of the path
 * RET  : 1 on success, 0 if fail
*/
int get_txt(const char* path, char** buf_str){
  int fd = open(path, O_RDONLY);
  if(fd == -1){
    fprintf(stderr, "%s\n", strerror(errno));
    return 1;
  }
  int lenght = size_file(path);
  int rc;
  *buf_str = malloc(lenght*sizeof(char));

  for(int i=0; i<lenght; i++){
    char buf;
    rc = read(fd, &buf, sizeof(char));
    strncat(*buf_str, &buf, sizeof(char));

    if(rc == -1){
      fprintf(stderr, "%s\n", strerror(errno));
      return 1;
    }
  }

  close(fd);
  return 0;
}


/*
 * print the usage of the program
*/
void print_usage(){
  fprintf(stderr,"[USAGE] correct usage : ./pattern_finder x word text\n\n"
         "ARGUMENTS : - <x> number of threads (int value)\n"
         "            - <word> word to find in the text\n"
         "            - <text> path of the text\n");
}


/*
 * check usage of the program. If arguments are wrong, stop the progam and print the usage
 * ARGS : <argv> number of string, <argv> strings took in arguments of the program
 * RET  : return 0 if args are ok, return 1 if not
*/
int usage(int argc, char** argv){
  if(argc != 4){
    print_usage();
    return 1;
  }

  size_t i = 0;
  while(i<strlen(argv[1])){   // check if the number of threads is an int
    if(!isdigit(argv[1][i])){
      fprintf(stderr,"number of threads must be an integer\n");
      print_usage();
      return 1;
    }
    i++;
  }

  for(int k=2; k<4; k++){
    size_t j = 0;
    while(j<strlen(argv[k])){
      if(!isalnum(argv[k][j]) && argv[k][j]!='.'){
        print_usage();
        return 1;
      }
      j++;
    }
  }

  return 0;
}


/*
 * free memory of args
 * ARG : elements to free
*/
void free_all(args *args){
  for(int i=0; args[i].txt[0] != '\0' ; i++){
    free(args[i].txt);
  }
}
