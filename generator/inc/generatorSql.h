#pragma once

#include "utils.h"
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>

class generatorDBWorker {
private:
  sqlite3 *db;

public:
  generatorDBWorker();
  int getLastID();
  ~generatorDBWorker() { sqlite3_close(db); };
};
