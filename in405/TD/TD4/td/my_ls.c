#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <pwd.h>

#include "my_ls.h"

char *print_type(const struct stat* file) {
  char *type = malloc(4*sizeof(char));

  switch (file->st_mode & S_IFMT) {
  case S_IFBLK:  sprintf(type,"devc");            break;
  case S_IFDIR:  sprintf(type,"diry");            break;
  case S_IFIFO:  sprintf(type,"fifo");            break;
  case S_IFLNK:  sprintf(type,"link");            break;
  case S_IFREG:  sprintf(type,"file");            break;
  case S_IFSOCK: sprintf(type,"sock");            break;
  default:       sprintf(type,"????");            break;
  }

  return type;
}
/*
char *print_perm(const struct stat *file) {
  char *perm = malloc(9*sizeof(char));

  sprintf("%c%c%c%c%c%c%c%c%c",
          (S_IRUSR & file->st_mode) ? 'r' : '-',
          (S_IWUSR & file->st_mode) ? 'w' : '-',
          (S_IRUSR & file->st_mode) ? 'r' : '-',
          (S_IRUSR & file->st_mode) ? 'r' : '-',
          (S_IRUSR & file->st_mode) ? 'r' : '-',
          (S_IRUSR & file->st_mode) ? 'r' : '-',
          (S_IRUSR & file->st_mode) ? 'r' : '-',
          (S_IRUSR & file->st_mode) ? 'r' : '-');
  return perm;
}
char print_owner(const struct stat *file) {
}*/

char *print_working_dir(const char* name) {
  DIR* rep = NULL;
  struct dirent* file_buf = NULL;

  if((rep = opendir(name)) == NULL){
    fprintf(stderr,"failed to open");
    exit(1);
  }

  while((file_buf = readdir(rep)) != NULL){
    if((strcmp(file_buf->d_name, "..") != 0) &&
      (file_buf->d_name[0] != '.'))
      printf("%s ", file_buf->d_name);
  }
}
