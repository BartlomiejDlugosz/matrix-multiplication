//
// Created by bartlomiej-dlugosz on 10/23/24.
//

#include "Matrix.h"

#include <assert.h>
#include <iostream>
#include <vector>

/* Creates a new matrix from a 1 dimensional list given the size of the matrix */
Matrix::Matrix(std::vector<int> list_rep, int m, int n) {
  assert(list_rep.size() == m * n);

  /* Initialize matrix array */
  const std::vector<int> row(n, 0);
  this->matrix = std::vector<std::vector<int>>(m, row);

  this->m = m;
  this->n = n;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      this->matrix[i][j] = list_rep[i * n + j];
    }
  }
}
