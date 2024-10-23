#include <chrono>
#include <iostream>
#include <random>

#include "Matrix.h"

int main() {
  int matrix1_m = 950;
  int matrix12_nm = 1000;
  int matrix2_n = 1050;

  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(1,100);

  std::vector<int> matrix1_arr;
  std::vector<int> matrix2_arr;
  for (int i = 0; i < matrix1_m * matrix12_nm; i++) {
    matrix1_arr.push_back(dist(rng));
  }

  for (int i = 0; i < matrix12_nm * matrix2_n; i++) {
    matrix2_arr.push_back(dist(rng));
  }

  Matrix matrix1 = Matrix(matrix1_arr, matrix1_m, matrix12_nm);
  Matrix matrix2 = Matrix(matrix2_arr, matrix12_nm, matrix2_n);

  auto t1 = std::chrono::high_resolution_clock::now();
  Matrix matrix3 = Matrix::multiply(matrix1, matrix2);
  auto t2 = std::chrono::high_resolution_clock::now();

  auto t3 = std::chrono::high_resolution_clock::now();
  Matrix matrix4 = Matrix::threaded_multiply(matrix1, matrix2);
  auto t4 = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double, std::milli> ms_not_threaded = t2 - t1;
  std::chrono::duration<double, std::milli> ms_threaded = t4 - t3;

  std::cout << "Time taken (Non-Threaded): " << ms_not_threaded << std::endl;
  std::cout << "Time taken (Threaded): " << ms_threaded << std::endl;

  return 0;
}
