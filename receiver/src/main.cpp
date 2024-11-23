#include "main.h"

int main() {
  Reader reader;
  DBWorker dbWorker;

  int a = 0, b = 7;
  while (true)
  {

    dbWorker.writeRecord(reader.readFromSender());
    dbWorker.readByIDRange(a, b);
  }
}