#include "receiverui.h"

#include "socketReader.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  ReceiverUI w;
  w.show();
  SocketReader reader;
  return a.exec();
}
