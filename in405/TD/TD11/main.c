#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

size_t size_file(const char* path){
  int fd = open(path, O_RDONLY);
  int lenght = lseek(fd, 0, SEEK_END); // position of the last char = size of the file
  close(fd);
  return lenght;
}

int get_txt(const char* path, char** buf_str){
  int fd = open(path, O_RDONLY);
  int lenght = size_file(path);
  int rc;
  *buf_str = malloc(lenght*sizeof(char));

  for(int i=0; i<lenght; i++){
    char buf;
    rc = read(fd, &buf, sizeof(char));
    strncat(*buf_str, &buf, sizeof(char));

    if(rc == -1){
      perror("read error");
      return 1;
    }

  }
  return 0;
}

int print_occ(char* path, char* txt, char* strToFind){
  get_txt(path, &txt);
  size_t lenght = size_file(path);

  for(size_t i=0; i<lenght; i++){
    if(txt[i] == strToFind[0]){
      for(size_t k=i+1; k<i+strlen(strToFind); k++){
        int j=1; // because we already check the first char

        if(txt[k] != strToFind[j])
          break;

        printf("k %d, %d\n", (int)k+1,(int)(i+strlen(strToFind)-k));

        if(k+1 == i+strlen(strToFind)-1)
          fprintf(stdout, "Occurence at %d\n", (int)i+1);

        j++;
      }
    }
  }

  return 0;
}

int main(int argc, char** argv){
  char* str = "";
  char* strToFind = argv[1];

  print_occ(argv[2], str, strToFind);

  return 0;
}
