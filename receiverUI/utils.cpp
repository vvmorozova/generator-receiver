#include "utils.h"
#include <QDebug>

std::string matrixToString(MatrixData matrixData) {
  std::string str;
  for (auto &i : matrixData.matrix) {
    for (auto &j : i) {
      str += std::to_string(j) + " ";
    }
  }
  return str;
}

bool isNumber(std::string str) {
  bool flag = true;
  int len = str.length();
  for (int i = 0; i < len; i++) {
    if (i == 0 && str[i] == '-' && len > 2) {
      continue;
    }
    if (isdigit(str[i]) == false) {
      flag = false;
      break;
    }
  }

  if (flag == true) {
    return true;
  } else {
    return false;
  }
}

void stringToMatrix(MatrixData &matrixData, std::string str, int m, int n) {
  std::string delimiter = " ";
  size_t pos = 0;
  int number;
  int i = 0, j = 0;
  std::vector<int> numTemp;
  while ((pos = str.find(delimiter)) != std::string::npos) {
    std::string subs = str.substr(0, pos);
    number = stoi(subs);
    numTemp.push_back(number);

    if (++j == m) {
      j = 0;
      i++;
      matrixData.matrix.push_back(std::move(numTemp));
      numTemp = {};
    }

    str.erase(0, pos + delimiter.length());
  }

  matrixData.matrix.push_back(std::move(numTemp));
}
