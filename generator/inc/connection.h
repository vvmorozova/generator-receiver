#pragma once

#include "utils.h"
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

class Sender {
public:
  Sender();
  void sendMatrix(MatrixData matrixData);
  ~Sender() { close(sender_fd); };

private:
  int sender_fd;
};