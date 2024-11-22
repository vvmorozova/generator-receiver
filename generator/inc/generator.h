#pragma once

#include <ctime>
#include <iostream>
#include <random>
#include <vector>

#include "utils.h"

class Generator {
public:
  MatrixData generate_matrix(int n, int m);

private:
  unsigned long matrix_id = 0;
};
