#pragma once

#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>
#include <string>

class Reader {
public:
  Reader();
  std::vector<std::vector<int>> readFromSender();
  ~Reader();

private:
  int server_fd;
  int client_fd;
};
