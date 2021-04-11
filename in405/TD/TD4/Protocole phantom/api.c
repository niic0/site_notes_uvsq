#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>

#include "internals.h"
#include "api.h"

int capture_tree(const char *path, struct file **phantom){
  DIR *pDir;
  struct dirent *entry;

  if((pDir = opendir(path)) == NULL){
    fprintf(stderr,"cannot open directory %s\n", path);
    return 1;
  }

  if(phantom == NULL){
    printf("phantom is NULL!\n");
    return 1;
  }

  (*phantom) = malloc(sizeof(struct file));
  if(*phantom == NULL) {
    fprintf(stderr,"malloc failed\n");
    return 1;
  }

  chdir(path);
  while ((entry = readdir(pDir)) != NULL){

    if(capture_file(entry->d_name,(*phantom))){
      fprintf(stderr,"error on capture_file");
      return 1;
    }

    (*phantom)->next = malloc(sizeof(struct file));
    if ((*phantom)->next == NULL){
      fprintf(stderr,"mallloc failed\n");
    }
    if(((*phantom)->type == FT_DIRECTORY) && ((*phantom)->name!=path)) {
      (*phantom)->attribute.child = malloc(sizeof(struct file));
      if(browse_directory((*phantom)->name, &(*phantom)->attribute.child)){
        fprintf(stderr,"error on browse_directory()\n");
        return 1;
      };
    }

    *phantom = (*phantom)->next;
  }

  closedir(pDir);

  return 0;
}

int create_phantom(const char *path, struct file *phantom){
  if(phantom == NULL || path == NULL) {
    fprintf(stderr,"phantom  or path is null\n");
  }

  while(phantom != NULL){
    if (phantom->type == FT_REGULAR){
      if(create_regular(phantom->name,phantom)){
        fprintf(stderr,"creat_regular() failed with %s\n", phantom->name);
        return 1;
      };
    }
    else if (phantom->type == FT_DIRECTORY){
      if(create_directory(phantom->name,phantom)){
        fprintf(stderr,"creat_directory() failed with %s\n", phantom->name);
        return 1;
      };
    }
    else if (phantom->type == FT_LINK){
      if(create_link(phantom->name,phantom)){
        fprintf(stderr,"creat_link failed with %s", phantom->name);
      };
    }
    else {
      fprintf(stderr,"type error for %s\n", phantom->name);
      return 1;
    }

    phantom = phantom->next;
  }
  return 0;
}
