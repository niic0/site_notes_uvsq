#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "io_file.h"

// Affichage du contenu d'un fichier
// \param	path			Nom/chemin du fichier à afficher
// \return					-1 si échec à l'ouverture, 0 sinon
int print(const char *path) {
	IO_FILE file;

  file = IO_open(path, O_RDONLY);

  if (file.desc < 0) {
    fprintf(stderr,"Open issue %s", path);
    return -1;
  }


	char *c = malloc(sizeof(char));
  if (!c) {fprintf(stderr,"Allocation problem"); return -1;}

	while(IO_char_read(file,c) > 0)
		fprintf(stdout,"%c",*c);

  return 0;
}

int main (int argc, char **argv) {
  print(argv[2]);

  return 0;
}
