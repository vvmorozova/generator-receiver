#pragma once

#include <arpa/inet.h>
#include <cstring>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>
#include <iostream>

class Sender {
public:
  Sender();
  void sendMatrix(std::vector<std::vector<int>> matrix, int n, int m);
  ~Sender() { close(sender_fd); };

private:
  int sender_fd;
};