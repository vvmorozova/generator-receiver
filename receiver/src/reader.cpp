#include "reader.h"

Reader::Reader() {
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  sockaddr_in address = {AF_INET, htons(8080), INADDR_ANY};
  bind(server_fd, (struct sockaddr *)&address, sizeof(address));
  listen(server_fd, 3);
  client_fd = accept(server_fd, nullptr, nullptr);
}

Reader::~Reader() {
  close(client_fd);
  close(server_fd);
}

std::vector<std::vector<int>> messageToMatrix(char *message) {
  std::string str = message;
  std::vector<std::vector<int>> numbers;
  std::string delimiter = " ";
  size_t pos = 0;
  int number;
  int n = -1, m = -1, i = 0, j = 0;
  std::cout << "messageToMatrix" << std::endl;
std::vector<int> numTemp;

  while ((pos = str.find(delimiter)) != std::string::npos) {
    number = stoi(str.substr(0, pos));
    std::cout << "num " << number << std::endl;
    if (n == -1)
      n = number;
    else if (m == -1)
      m = number;
    else
    {
        numTemp.push_back(number);
        if (++j == m)
        {
            j = 0;
            i++;
            numbers.push_back(numTemp);
            numTemp = {};

        }

    }
    str.erase(0, pos + delimiter.length());
  }
  // numbers[i][j] = number;
  numTemp.push_back(number);
  numbers.push_back(numTemp);
  return numbers;
}

std::vector<std::vector<int>> Reader::readFromSender() {
  // char buffer[1024] = "2 2 0 1 2 1";
  char buffer[1024] = {0};
  std::cout << "Before read " << buffer;
  read(client_fd, buffer, 1024);
  std::cout << "Got msg " << buffer;
  return messageToMatrix(buffer);
}