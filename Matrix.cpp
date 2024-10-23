//
// Created by bartlomiej-dlugosz on 10/23/24.
//

#include "Matrix.h"

#include <assert.h>
#include <iostream>
#include <thread>
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

void Matrix::thread_multiply(int thread_index, int total_threads, Matrix& res, const Matrix& matrix1, const Matrix& matrix2) {
  int rows_per_thread = matrix1.m / total_threads;
  int start_row = thread_index * rows_per_thread;
  int end_row = (thread_index == total_threads - 1) ? matrix1.m : start_row + rows_per_thread;

  for (int i = start_row; i < end_row; i++) {
    for (int j = 0; j < matrix2.n; j++) {
      int sum = 0;
      for (int k = 0; k < matrix1.n; k++) {
        sum += matrix1.matrix[i][k] * matrix2.matrix[k][j];
      }
      res.matrix[i][j] = sum;
    }
  }
}

/* Multiplies the matrices in the order provided
 * Uses multiple threads to achieve better performance */
Matrix Matrix::threaded_multiply(const Matrix& matrix1, const Matrix& matrix2) {
  assert(matrix1.n == matrix2.m);
  const auto thread_count = std::thread::hardware_concurrency();

  Matrix res(matrix1.m, matrix2.n);

  std::vector<std::thread> threads;
  threads.reserve(thread_count);
  for (unsigned int i = 0; i < thread_count; i++) {
    threads.emplace_back(&Matrix::thread_multiply, i, thread_count, std::ref(res), std::cref(matrix1), std::cref(matrix2));
  }

  for (auto& thread : threads) {
    thread.join();
  }

  return res;
}
