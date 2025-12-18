#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int server_create(struct server *srv){
    srv->listen_fd = socket(AF_INET, SOCK_STREAM, 0); // TCP socket
    if (srv->listen_fd < 0) {
        perror("Socket creation failed -_-");
        return -1;
    }
    srv->client_fd = -1; // No client connected yet

    memset(&srv->serv_address, 0, sizeof(srv->serv_address)); // Clear garbage
    srv->serv_address.sin_family = AF_INET;
    srv->serv_address.sin_addr.s_addr = INADDR_ANY;
    srv->serv_address.sin_port = 0; // Port will be set in server_start

    return 0;
}

int server_start(struct server *srv, int port){
    srv->serv_address.sin_port = htons(port); // Set port
    int reuse_port = 1;
    setsockopt(srv->listen_fd, SOL_SOCKET, SO_REUSEADDR, &reuse_port, sizeof(reuse_port)); // Allow quick port reuse
    
    if (bind(srv->listen_fd, (struct sockaddr *)&srv->serv_address, sizeof(srv->serv_address)) < 0) {
        perror("Bind failed -_-");
        return -1;
    }
    
    return 0;
}

int server_listen(struct server *srv){
    if (listen(srv->listen_fd, 5)){
        perror("Listen failed -_-");
        return -1;
    }
    return 0;
}

int server_accept(struct server *srv){
    socklen_t addr_len = sizeof(srv->client_address); // Length of client address
    srv->client_fd = accept(srv->listen_fd, (struct sockaddr *)&srv->client_address, &addr_len); // Accept a client connection
    if (srv->client_fd < 0) {
        perror("Accept failed -_-");
        return -1;
    }
    return 0;
}

int handle_connection(struct server *srv){
    // Client send request filename to server
    char buffer[1024];
    ssize_t bytes_read = read(srv->client_fd, buffer, sizeof(buffer) - 1);

    if (bytes_read < 0) {
        perror("Read failed -_-");
        return -1;  
    } else if (bytes_read == 0) {
        printf("Client disconnected -_-\n");
        return -1;
    } else {
        buffer[bytes_read] = '\0';   // Null-terminate and print the received filename
        printf("Received filename: %s\n", buffer);
    } 
}


void server_close(struct server *srv){

}