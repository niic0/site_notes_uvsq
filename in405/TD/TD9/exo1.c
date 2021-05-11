#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void hello_thread(void* arg){
  pthread_t thread;

  pthread_create(&thread, NULL, (void*) printf, "Hello World!\n");

  pthread_join(thread,NULL);
}

void* affichage_int(void* arg){
  printf("%d\n", (int*) arg);
  return NULL;
}

void alea_thread(void* arg) {
  pthread_t thread;

  srand(time(NULL));
  int i = rand();

  pthread_create(&thread, NULL, (void*) affichage_int, &i);

  pthread_join(thread,NULL);
}

void alea_tab_thread(void* arg){
  srand(time(NULL));

  int r[5];
  int sum = 0;

  for(int i=0; i<5 ;i++) {
    r[i]=rand()%100;
    printf("%d\n",r[i]);
    sum += r[i];
  }

  int M = sum/5;

  printf("Moyenne :", M);
}

int main() {
  void* arg = NULL;

  // hello_thread(arg);
  // alea_thread(arg);
  alea_tab_thread(arg);

  return 0;
}
