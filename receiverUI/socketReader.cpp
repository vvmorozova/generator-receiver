#include "socketReader.h"

long long int getNumber(std::string &str) {
  std::string delimiter = "]";
  size_t pos = 0;
  long long int number;
  pos = str.find(delimiter);
  std::cout << "str " << str << std::endl;
  number = stoi(str.substr(1, pos));
  str.erase(0, pos + delimiter.length());
  return number;
}

unsigned long int ulGetNumber(std::string &str) {
  std::string delimiter = "]";
  size_t pos = 0;
  long long int number;
  pos = str.find(delimiter);
  std::cout << "str " << str << std::endl;
  number = stoul(str.substr(1, pos));
  str.erase(0, pos + delimiter.length());
  return number;
}

MatrixData messageToMatrix(char *message) {
  std::string str = message;
  MatrixData result;
  std::cout << "messageToMatrix " << message << std::endl;
//  if (!message)
//    return NULL;
  result.id = ulGetNumber(str);
  result.genTime = getNumber(str);
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

  // QByteArray data = clientSocket->readAll();
  //   std::string strData = (QString(clientSocket->readAll())).toStdString();
//   QString qStrData = QString(clientSocket->readAll());
//   std::string strData = qStrData.toStdString();
//   qDebug() << "strData:" << qStrData;
  DBWorker worker;
  worker.writeRecord(messageToMatrix((clientSocket->readAll()).data()));
}
