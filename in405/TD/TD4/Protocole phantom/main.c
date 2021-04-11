#include "api.h"
#include "internals.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    struct file *parent;
    parent = malloc(sizeof(struct file));

    if(parent == NULL) {
        fprintf(stdout,"error on malloc\n");
        return EXIT_FAILURE;
    }
    if (argc != 3) {
        printf("Bad usage: %s src dest\n"
               "   - src : source directory\n"
               "   - dest: phantom directory\n", argv[0]);
        return EXIT_FAILURE;
    }

    capture_tree(argv[1], &parent);
    create_phantom(argv[2], parent);

    while(parent != NULL){
        free(parent);
        parent = parent->next;
    }

    return EXIT_SUCCESS;
}
