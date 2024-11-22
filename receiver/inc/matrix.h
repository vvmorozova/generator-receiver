#pragma once

#include <ctime>
#include <vector>

struct MatrixData {
  int n, m;
  std::vector<std::vector<int>> matrix;
  unsigned long id;
  std::time_t genTime;
};