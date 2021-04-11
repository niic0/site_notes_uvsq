#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>

void fork_Hworld() {
  pid_t p = fork();

  if(p){
    fprintf(stdout, "Hello world! pere");
    wait(NULL);
  }
  else {
    sleep(1);
    fprintf(stdout, "Hello world! fils");
  }
}

void fork_pid() {
  pid_t p = fork();

  if(p) {
    fprintf(stdout, "Mon PID est '%d' et celui de mon fils est %d\n",getpid(), p);
    wait(NULL);
  }
  else {
    sleep(1);
    fprintf(stdout, "Mon PID est '%d' et celui de mon père est %d", getppid(), p);
  }
}

void fork_rand() {
  pid_t p;
  int rand_fils, rand_pere;
  srand(time(NULL));
  p = fork();

  if(p){
    wait(&rand_pere);
    fprintf(stdout,"pere : %d\n", WEXITSTATUS(rand_pere));
  }
  else {
    rand_fils =1+ (rand()%50);
    fprintf(stdout,"fils : %d\n",rand_fils);
    exit(rand_fils);
  }
}

void fork_rand_times() {
  pid_t p;
  srand(time(NULL));
  int t = 1+rand()%10;
  for(int i=0 ;i<10 ;i++) {
    p = fork();
    if(!p){
      sleep(t);
      fprintf(stdout,"PID : %d",getpid());
    }
  }
  for(int i=0 ;i<10 ;i++) {
    wait(&t);
    fprintf(stdout,"%d fini\n",p);
  }
}

void multiple_fork(int m, int n) {
  pid_t p;
  int i,k,count;

  for(i=0; i<m; i++) {
    for(k=0; k<n; k++) {
      sleep(2);
      p = fork();
      if(!p) fprintf(stdout, "child '%d'\n",getpid());
    }
  }

  for(i=0; i<m; i++){
    for(k=0; k<n; k++) {
      wait(NULL);
      count++;
    }
  }

  fprintf(stdout,"Process created : %d \n",count);
}

void child_1 () {

}

int main() {
//  fork_Hworld();
//  fork_pid();
//  fork_rand();
//  fork_rand_times();
  multiple_fork(2,5);
  return 0;
}
