#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main() {
  char *db[10];
  *db = malloc(100*sizeof(char));

  time_t t = time(NULL);
  struct tm *t_info = localtime(&t);

  db[0] = "test";
  db[1] =

  int tube[2];
  pipe(tube);

  pid_t pid = fork();

  for(int i=0; i<10; i++){
    if(pid) {
      write(tube[1], db[i], 16*sizeof(char));
      fprintf(stdout,"pid: %s\n", db[i]);
    }
    else {
      read(tube[0], db[i], 16);
      fprintf(stdout, "!pid: %s\n",db[i]);
    }
  }

  return 0;
}
