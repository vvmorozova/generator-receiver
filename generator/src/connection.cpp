#include "connection.h"

Sender::Sender() {
  sender_fd = socket(AF_INET, SOCK_STREAM, 0);
  sockaddr_in address = {AF_INET, htons(8080), inet_addr("127.0.0.1")};
  connect(sender_fd, (struct sockaddr *)&address, sizeof(address));
}

std::string matrixToMessage(std::vector<std::vector<int>> matrix, int n,
                            int m) {
  std::string str = std::to_string(n) + " " + std::to_string(m) + " ";
  for (auto &i : matrix) {
    for (auto &j : i) {
      str += std::to_string(j) + " ";
      std::cout << "j " << j << std::endl;
    }
  }

  std::cout << "str " << str << std::endl;
  return str;
}

void Sender::sendMatrix(std::vector<std::vector<int>> matrix, int n, int m) {
  std::string strMsg = matrixToMessage(matrix, n, m);
  const char *message = (strMsg).c_str();
  std::cout << "generator matrix" << " " << message << std::endl;
  send(sender_fd, message, strlen(message), 0);
}
