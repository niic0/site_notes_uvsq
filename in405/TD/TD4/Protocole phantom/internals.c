#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <libgen.h>

#include "internals.h"

// Capture meta data of a file and put them in the file structure
int capture_file(const char *path, struct file *parent) {
  if(!path){
    fprintf(stderr,"no path\n");
    return 1;
  }

  struct stat file;

  // If it returns another thing than 0, we enter in the condition then errno is set properly
  if (stat(path,&file)){
    fprintf(stderr,"stat function error for path <%s> : %s\n\n",path, strerror(errno));
    return 1;
  }

  strcpy(parent->name,path);
  parent->user_id = file.st_uid;
  parent->mode = file.st_mode;

  parent->next = NULL;   // The api will fil this value

  if(S_ISREG(file.st_mode)){
//    printf("%15s is reg\n",path);
    parent->type = FT_REGULAR;
    parent->attribute.size = file.st_size;
  }
  else if(S_ISDIR(file.st_mode)) {
//    printf("%15s is dir\n",path);
    parent->type = FT_DIRECTORY;
    parent->attribute.child = NULL;
  }
  else if(S_ISLNK(file.st_mode)){
//    printf("%15s is link\n",path);
    parent->type = FT_LINK;
    readlink(path,&parent->attribute.target[64] , 64);
  }

  return 0;
}


int browse_directory(const char *path, struct file **current){
  if(strcmp(".", path)==0 || strcmp("..",path)==0) // "." = previous directory
    return 0;                                      // ".." = actual directory

  DIR *pDir;
  struct dirent *entry;

  if((pDir = opendir(path)) == NULL){
    fprintf(stderr,"cannot open directory %s\n", path);
    return 1;
  }
  if(current == NULL){
    printf("current is NULL!\n");
    return 1;
  }

  chdir(path);
  printf("\browsing %s... \n\n",path);

  while ((entry = readdir(pDir)) != NULL){
    (*current)->next = malloc(sizeof(struct file));
    if(capture_file(entry->d_name, (*current)->next)){
      fprintf(stderr,"error with capture_file() \n");
      return 1;
    }
  }

  printf("back to original directory... \n\n");

  chdir("..");

  closedir(pDir);

  return 0;
}


int create_regular(const char *path, const struct file *regular){
  int fd = -1;
  int sz,rc;

  fd = open(path, O_CREAT | O_WRONLY, regular->mode);

  if (fd == -1) {
    fprintf(stderr, "ERR on file creation : %s\n", strerror(errno));
    return 1;
  }

  sz = write(fd, "", regular->attribute.size);

  if (sz != regular->attribute.size){
    fprintf(stderr, "ERR on file writing : %s\n", strerror(errno));
    return 1;
  }

  rc = close(fd);
  if (rc){
    fprintf(stderr, "ERR on file closure : %s\n", strerror(errno));
    return 1;
  }

  return 0;
}

int create_directory(const char *path, const struct file *directory) {
  int rc;

  rc = mkdir(path, directory->mode);
  if(rc) {
    fprintf(stderr, "ERR on dir creation : %s\n", strerror(errno));
    return 1;
  }

  return 0;
}

int create_link(const char *path, const struct file *link){
  int rc = symlink(path, link->attribute.target);
  if(rc){
    fprintf(stderr,"ERR on link creation : %s\n", strerror(errno));
  }
  return 0;
}
