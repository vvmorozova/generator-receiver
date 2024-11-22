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

long long int getNumber(std::string &str) {
  std::string delimiter = "]";
  size_t pos = 0;
  long long int number;
  pos = str.find(delimiter);
  number = stoi(str.substr(1, pos));
  str.erase(0, pos + delimiter.length());
  return number;
}

MatrixData messageToMatrix(char *message) {
  std::string str = message;
  MatrixData result;
  std::cout << "messageToMatrix" << std::endl;
  result.id = getNumber(str);
  result.genTime = getNumber(str);
  result.m = getNumber(str);
  result.n = getNumber(str);
  str = str.substr(1, str.length() - 2);

  stringToMatrix(result, str, result.m, result.n);

  return result;
}

MatrixData Reader::readFromSender() {
  // char buffer[1024] = "[0][1732285013][2][2][-85 17 -81 -31 ]";
  char buffer[1024] = {0};
  std::cout << "Before read " << buffer;
  read(client_fd, buffer, 1024);
  std::cout << "Got msg " << buffer;
  return messageToMatrix(buffer);
}