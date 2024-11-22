#pragma once

#include "utils.h"
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

class Reader {
public:
  Reader();
  MatrixData readFromSender();
  ~Reader();

private:
  int server_fd;
  int client_fd;
};
