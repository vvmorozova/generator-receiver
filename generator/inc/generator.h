#pragma once

#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

#include "utils.h"

class Generator {
public:
  MatrixData generate_matrix(int n, int m);
  Generator();

private:
  unsigned long matrix_id;
};
