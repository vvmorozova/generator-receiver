#include "main.h"

int main() {
  Reader reader;
  DBWorker dbWorker;

  while (true)
    // MatrixData res = reader.readFromSender();
    dbWorker.writeRecord(reader.readFromSender());
}