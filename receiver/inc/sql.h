#pragma once

#include "utils.h"
#include <iostream>
#include <sqlite3.h>
#include <vector>

class DBWorker {
private:
  sqlite3 *db;

public:
  DBWorker();
  std::vector<MatrixData> readByIDRange(unsigned long from, unsigned long to);
  void writeRecord(MatrixData matrixData);
  ~DBWorker() { sqlite3_close(db); };
};
