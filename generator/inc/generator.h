#pragma once

#include <random>
#include <vector>
#include <iostream>

class Generator {
public:
  std::vector<std::vector<int>> generate_matrix(int n, int m);

private:
  unsigned long matrix_id = 0;
};
