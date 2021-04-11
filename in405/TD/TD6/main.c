#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/times.h>

#define HOME "/home/nicof"

void fils_ps(){
  execlp("ps","ps","-A",NULL);
}

void fils_ls(){
  execlp("ls","ls","-l",HOME,NULL);
}

void fils_find(int b){
  char *args[7];
  args[0] = "find";
  args[1] = HOME;
  args[2] = "-maxdepth";
  args[3] = "1";
  args[4] = "-type";
  args[5] = b?"d":"f";
  args[6] = NULL;
  execvp("find",args);
}

void fork_test() {
  pid_t p;
  int r;
  p = fork();
  if(p){
    wait(&r);
  }
  wait(NULL);
  if(!fork()) fils_find(1);
  wait(NULL);
}

void fils_qui_compte(){
  for(int i=0; i<6; i++){
    sleep(1);
    printf("%d\n",i);
  }
  exit(0);
}

void stop_test(){
  pid_t p;
  p = fork();
  if(!p) fils_qui_compte();
  sleep(3);
  kill(p, SIGINT);
  sleep(5);
  kill(p,SIGCONT);
  wait(NULL);
}

void time_set(){
  struct tms horloge;
  if(fork()) fils_ls();
  wait(NULL);
  times(&horloge);
  long d = horloge.tms_cutime+horloge.tms_cstime;
  float t = ((float)horloge.tms_cutime + (float)horloge.tms_cstime)/((float)sysconf(_SC_CLK_TCK));
  fprintf(stdout,"temps écoulé : %f pour %ld cycles\n",t,d);
}

int main(int argc, char** argv){
  // fork_test();
  //time_set();
  stop_test();
  return 0;
}
