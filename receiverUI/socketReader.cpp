#include "socketReader.h"

long long int getNumber(std::string &str) {
  std::string delimiter = "]";
  size_t pos = 0;
  long long int number;

  // std::cout << "getNumber str " << str << std::endl;
  if (str == "")
    return 0;

  pos = str.find(delimiter);
  std::string subs = str.substr(1, pos);
  std::cout << " SUBS " << subs << std::endl;
  if (!isNumber(subs))
    number = 0;
  else
    number = stoi(subs);
  str.erase(0, pos + delimiter.length());
  return number;
}

unsigned long int ulGetNumber(std::string &str) {
  std::string delimiter = "]";
  size_t pos = 0;
  long long int number;
  if (str == "")
    return 0;

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
  std::cout << " messageToMatrix id " << result.id << " m " << result.m << " n "
            << result.n << std::endl;
  str = str.substr(1, str.length() - 2);
  stringToMatrix(result, str, result.m, result.n);
  return result;
}

void SocketReader::onReadyRead() {
  if (!clientSocket) {
    return;
  }

  DBWorker worker;
  auto qdata = clientSocket->readAll();
  auto str = (qdata).data();
  MatrixData matrixData = messageToMatrix(str);
  worker.writeRecord(matrixData);
}
