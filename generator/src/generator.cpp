#include "generator.h"

#define MIN_VALUE -100
#define MAX_VALUE 100

MatrixData Generator::generate_matrix(int n, int m) {

  MatrixData result;
  std::mt19937 prng(std::random_device{}());
  std::uniform_int_distribution<int> dist(MIN_VALUE, MAX_VALUE);

  std::cout << "in genenrate matrix " << std::endl;
  for (int i = 0; i < n; i++) {
    std::vector<int> collumn;
    for (int j = 0; j < m; j++) {
      collumn.push_back(dist(prng));
    }
    result.matrix.push_back(collumn);
  }
  result.id = matrix_id;
  result.n = n;
  result.m = m;
  result.genTime = std::time(nullptr);
  matrix_id++;

  return result;
}
