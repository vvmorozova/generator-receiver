#include "generator.h"

#define MIN_VALUE -100
#define MAX_VALUE 100

std::vector<std::vector<int>> Generator::generate_matrix(int n, int m) {

  std::vector<std::vector<int>> result;
  std::mt19937 prng(std::random_device{}());
  std::uniform_int_distribution<int> dist(MIN_VALUE, MAX_VALUE);

  std::cout << "in genenrate matrix " << std::endl;
  for (int i = 0; i < n; i++) {
    std::vector<int> collumn;
    for (int j = 0; j < m; j++) {
      collumn.push_back(dist(prng));
    }
    result.push_back(collumn);
  }
  matrix_id++;

  return result;
}
