#pragma once

#include "utils.h"
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>

class DBWorker {
private:
  sqlite3 *db;

public:
  DBWorker();
  std::vector<MatrixData> readByIDRange(unsigned long from, unsigned long to);
  void writeRecord(MatrixData matrixData);
  std::string getLogs();
  ~DBWorker() { sqlite3_close(db); };
};
