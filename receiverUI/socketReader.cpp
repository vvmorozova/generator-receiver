#include "socketReader.h"

long long int getNumber(std::string &str) {
  std::string delimiter = "]";
  size_t pos = 0;
  long long int number;

  std::cout << "getNumber str " << str << std::endl;
  if (str == "")
    return 0;

  pos = str.find(delimiter);
  std::string subs = str.substr(1, pos);
  // if (!isNumber(subs))
  //   return 0;
  number = stoi(str.substr(1, pos));
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
  str = str.substr(1, str.length() - 2);
  std::cout << "messageToMatrix1 " << str << " m " << result.m << " n "
            << result.n << std::endl;
  stringToMatrix(result, str, result.m, result.n);
  std::cout << "result.matrix" << std::endl;
  for (auto i : result.matrix) {
    for (auto j : i)
      std::cout << j << " ";
  }
  std::cout << std::endl;
  return result;
}

void SocketReader::onReadyRead() {
  if (!clientSocket) {
    return;
  }

  DBWorker worker;
  auto qdata = clientSocket->readAll();
  qDebug() << "qdata " << qdata;
  auto str = (qdata).data();
  qDebug() << "(clientSocket->readAll()).data()" << str;
  MatrixData matrixData = messageToMatrix(str);
  worker.writeRecord(matrixData);
}
