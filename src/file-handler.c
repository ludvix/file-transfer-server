#include "file-handler.h"
#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 // Open file in binary mode
    int send_file(struct server *srv, char *buffer){
    FILE *file_from_server = fopen(buffer, "rb");
    if (file_from_server == NULL) {
        perror("File open failed -_-");
        return -1;
    }

    char buffer[1024];
    size_t bytes_read;
    while(bytes_read = fread(buffer, 1, sizeof(buffer), file_from_server)) { // Read file in chunks and send to client
        if (send(srv->client_fd, buffer, bytes_read, 0) < 0) {
            perror("Send failed -_-");
            fclose(file_from_server);
            return -1;
        }
    }
    fclose(file_from_server);
    printf("File transfer complete! :) \n");
    return 0;
}