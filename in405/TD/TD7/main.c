#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void tube_anonyme(){
  int tube[2];
  pipe(tube);

  pid_t pid = fork();
  char str[16] = "Hello World!";

  if(pid) {
    write(tube[1], str, 16*sizeof(char));
    fprintf(stdout,"pid: %s\n", str);
  }
  else {
    read(tube[0], str, 16);
    fprintf(stdout, "!pid: %s\n",str);
  }
}

void tube_nomme() {
  mkfifo("/tmp/testtube", 0666);

  int fd[2];
  int ent = 14;

  if(fork()) {
    fd[0] = open("/tmp/testtube", O_WRONLY);
    write(fd[0], &ent, sizeof(int));
    printf("%d\n",ent);
  }
/*  else {
    read()
    printf("%d\n",ent2);
  }*/
}

int main(){
  //tube_anonyme();
  //tube_nomme();

  return 0;
}
