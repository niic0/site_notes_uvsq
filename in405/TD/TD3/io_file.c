#include "io_file.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

IO_FILE IO_open(const char *path, int access) {
  IO_FILE ret;
  ret.path = strdup(path);
  ret.access = access;

  if (!path) {
    ret.desc = -1;
    return ret;
  }
  if (access & O_CREAT) {
    ret.desc = open(path, access, S_IRUSR|S_IWUSR);   // On créer le fichier et on donne les droits
    return ret;
  }
  open(path,access);
  return ret;
}

int IO_close(IO_FILE file) {
  if (file.desc < 0){
    fprintf(stderr,"Closing file with wrong description %d\n", file.desc);
    return -1;
  }

  int ret = close(file.desc);
  if (file.path) free(file.path);

  return ret;
}

int IO_remove(const char *path) {
  if (!path) {
    fprintf(stderr,"Removing file with no path \n");
    return -1;
  }

  if (remove(path))
    return 0;

  return -1;
}


int IO_char_read(IO_FILE file,char *c) {
  if (file.desc < 0) {
    fprintf(stderr, "attempting to read file with wrong descriptor %d\n", file.desc);
    return -1;
  }

  if (!c) {
    fprintf(stderr, "attempting to read into NULL");
    return -1;
  }

  if (!((file.access == O_RDONLY) || (file.access & O_RDWR))){
    fprintf(stderr,"attempting to read withour permission");
    return -1;
  }

  int ret = read(file.desc, c, 1);
  if (ret < 0)
    fprintf(stderr,"read error");

  return ret;
}

int IO_char_write(IO_FILE file, const char c) {
  if (file.desc < 0) {
    fprintf(stderr, "attempting to write file with wrong descriptor %d\n", file.desc);
    return -1;
  }

  if (!c) {
    fprintf(stderr, "attempting to write into NULL");
    return -1;
  }

  if (!((file.access == O_RDONLY) || (file.access & O_RDWR))){
    fprintf(stderr,"attempting to write withour permission");
    return -1;
  }

  int ret = write(file.desc, &c, 1);
  if (ret < 0)
    fprintf(stderr,"write error");

  return ret;
}
