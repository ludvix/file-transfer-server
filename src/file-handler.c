#include "file-handler.h"
#include <stdio.h>
#include <stdlib.h>

 // Open file in binary mode
    int send_file(struct server *srv, char *buffer){
    FILE *file_from_server = fopen(buffer, "rb");
    if (file_from_server == NULL) {
        perror("File open failed -_-");
        return -1;
    }
}