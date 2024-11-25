#include "connection.h"

Sender::Sender() {
  sender_fd = socket(AF_INET, SOCK_STREAM, 0);
  sockaddr_in address = {AF_INET, htons(8080), inet_addr("127.0.0.1")};
  connect(sender_fd, (struct sockaddr *)&address, sizeof(address));
}

// [порядковый id матрицы][время генерации][m][n][тело матрицы]
std::string matrixToMessage(MatrixData matrixData) {
  std::string str = "[" + std::to_string(matrixData.id) + "]";
  str += "[" + std::to_string(matrixData.genTime) + "]";
  str += "[" + std::to_string(matrixData.m) + "]";
  str += "[" + std::to_string(matrixData.n) + "]";

  str += "[";
  for (auto &i : matrixData.matrix) {
    for (auto &j : i) {
      str += std::to_string(j) + " ";
    }
  }
  str += "]";

  return str;
}

void Sender::sendMatrix(MatrixData matrixData) {
  std::string strMsg = matrixToMessage(matrixData);
  const char *message = (strMsg).c_str();
  send(sender_fd, message, strlen(message), 0);
}
