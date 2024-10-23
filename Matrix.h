//
// Created by bartlomiej-dlugosz on 10/23/24.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <vector>

class Matrix {
public:
  Matrix(int m, int n);
  Matrix(std::vector<int> list_rep, int m, int n);

private:
  /* Represents the matrix in the form {{1, 2, ...}, {1, 2, ...}}
   * where each outer array is a row and each inner array is a column */
  std::vector<std::vector<int>> matrix;
  int m;
  int n;
};

#endif //MATRIX_H
