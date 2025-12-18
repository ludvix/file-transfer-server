#include "file-handler.h"
#include "server.h"

int main(){
    struct server srv;

    server_create(&srv);
    server_start(&srv, 8080);
    server_listen(&srv);
    
    server_accept(&srv);
    handle_connection(&srv);
    
    server_close(&srv);

    return 0;
}
