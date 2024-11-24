#include "utils.h"

std::string matrixToString(MatrixData matrixData) {
  std::string str;
  for (auto &i : matrixData.matrix) {
    for (auto &j : i) {
      str += std::to_string(j) + " ";
    }
  }
  return str;
}

void stringToMatrix(MatrixData &matrixData, std::string str, int m, int n) {
  std::string delimiter = " ";
  size_t pos = 0;
  int number;
  int i = 0, j = 0;
  std::vector<int> numTemp;

  while ((pos = str.find(delimiter)) != std::string::npos) {
    number = stoi(str.substr(0, pos));
    std::cout << "num " << number << std::endl;
    numTemp.push_back(number);

    if (++j == m) {
      j = 0;
      i++;
      matrixData.matrix.push_back(numTemp);
      numTemp = {};
    }

    str.erase(0, pos + delimiter.length());
  }

  matrixData.matrix.push_back(numTemp);
}
