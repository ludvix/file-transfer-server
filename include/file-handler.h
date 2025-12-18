#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "server.h"

int send_file(struct server *srv, const char *filename);

#endif