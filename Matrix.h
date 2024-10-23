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

  static Matrix multiply(Matrix, Matrix);
  static Matrix threaded_multiply(const Matrix&, const Matrix&);

  void set(int m, int n, int val);
  int get(int m, int n);

private:
  static void thread_multiply(int thread_index, int total_threads, Matrix& res, const Matrix& matrix1, const Matrix& matrix2);
  /* Represents the matrix in the form {{1, 2, ...}, {1, 2, ...}}
   * where each outer array is a row and each inner array is a column */
  std::vector<std::vector<int>> matrix;
  int m;
  int n;
};

#endif //MATRIX_H
