#pragma once

#include <arpa/inet.h>
#include <cstring>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>
#include <iostream>
#include "matrix.h"

class Sender {
public:
  Sender();
  void sendMatrix(MatrixData matrixData);
  ~Sender() { close(sender_fd); };

private:
  int sender_fd;
};