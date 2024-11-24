#include "socketReader.h"

long long int getNumber(std::string &str) {
  std::string delimiter = "]";
  size_t pos = 0;
  long long int number;
  pos = str.find(delimiter);
  number = stoi(str.substr(1, pos));
  str.erase(0, pos + delimiter.length());
  return number;
}

unsigned long int ulGetNumber(std::string &str) {
  std::string delimiter = "]";
  size_t pos = 0;
  long long int number;
  pos = str.find(delimiter);
  number = stoul(str.substr(1, pos));
  str.erase(0, pos + delimiter.length());
  return number;
}

MatrixData messageToMatrix(char *message) {
  std::string str = message;
  MatrixData result;
  result.id = ulGetNumber(str);
  result.genTime = ulGetNumber(str);
  result.m = getNumber(str);
  result.n = getNumber(str);
  str = str.substr(1, str.length() - 2);
  stringToMatrix(result, str, result.m, result.n);

  return result;
}

void SocketReader::onReadyRead() {
  if (!clientSocket) {
    return;
  }

  DBWorker worker;
  worker.writeRecord(messageToMatrix((clientSocket->readAll()).data()));
}
