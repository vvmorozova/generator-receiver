#pragma once

#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

#include "generatorSql.h"
#include "utils.h"

class Generator {
public:
  Generator();
  MatrixData generate_matrix(int n, int m);

private:
  unsigned long matrix_id;
};
