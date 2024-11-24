#pragma once

#include <ctime>
#include <vector>
#include <string>
#include <iostream>

struct MatrixData {
  int n, m;
  std::vector<std::vector<int>> matrix;
  unsigned long id;
  std::time_t genTime;
};

std::string matrixToString(MatrixData matrixData);
void stringToMatrix(MatrixData &matrixData, std::string str, int m, int n);