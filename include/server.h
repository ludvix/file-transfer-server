#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>
#include <sys/socket.h>

struct server{
    int listen_fd;
    int client_fd;
    struct sockaddr_in serv_address;
    struct sockaddr_in client_address;
    socklen_t client_address_length;
};

int server_create(struct server *srv);
int server_start(struct server *srv, int port);
int server_listen(struct server *srv);
int server_accept(struct server *srv);
int handle_connection(struct server *srv);
void server_close(struct server *srv);

#endif

