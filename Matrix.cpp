//
// Created by bartlomiej-dlugosz on 10/23/24.
//

#include "Matrix.h"

#include <assert.h>
#include <iostream>
#include <vector>

/* Initialize empty matrix */
Matrix::Matrix(int m, int n) {
  const std::vector<int> row(n, 0);
  this->matrix = std::vector<std::vector<int>>(m, row);

  this->m = m;
  this->n = n;
}

/* Creates a new matrix from a 1 dimensional list given the size of the matrix */
Matrix::Matrix(std::vector<int> list_rep, int m, int n) : Matrix(m, n) {
  assert(list_rep.size() == m * n);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      this->matrix[i][j] = list_rep[i * n + j];
    }
  }
}

void Matrix::set(int m, int n, int val) {
  this->matrix[m][n] = val;
}

int Matrix::get(int m, int n) {
  return this->matrix[m][n];
}


Matrix Matrix::multiply(Matrix matrix1, Matrix matrix2) {
  assert(matrix1.m == matrix2.n);

  Matrix res = Matrix(matrix1.m, matrix2.n);
  for (int i = 0; i < matrix1.m; i++) {
    for (int j = 0; j < matrix2.n; j++) {
      int sum = 0;
      for (int r = 0; r < matrix1.n; r++) {
        int term1 = matrix1.matrix[i][r];
        int term2 = matrix2.matrix[r][j];
        sum += term1 * term2;
      }
      res.matrix[i][j] = sum;
    }
  }
  return res;
}
