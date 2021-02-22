#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//fonction itérative
int slenght_it (char* c){
  int cmpt=0;
  while (c[cmpt]!='\0') cmpt++;
  return cmpt;
}

//fonction récursive
int slenght_re (char* c){
  if (*(c) == '\0') return 0;
  return 1+(slenght_re(c+1));
}

//fonction itérative
int strcmp_it(char* str1, char* str2){
  if (strlen(str1)>strlen(str2)) return 1;
  if (strlen(str1)==strlen(str2)) return 0;
  if (strlen(str1)<strlen(str2)) return -1;
  exit (0);
}

int str_miroir (char* str1, char* str2) {
  int m,d; //m monter, d descend
  m = 0;
  d = strlen(str2)-1;
  while (d != 0 && m!=strlen(str2)){
    if(str1[m] != str2[d]) return 0;
    m++;
    d--;
  }
  return 1;
}

int main(int argc, char** argv) {
  //int i = slenght_re(argv[1]);
  int y = str_miroir(argv[1],argv[2]);
  printf("%d\n",y);
  return 0;
}
