#include <iostream>
#include "Matrix.h"

int main() {
  Matrix matrix1 = Matrix({2, 3, 4, 1, 0, 0}, 2, 3);
  Matrix matrix2 = Matrix({0, 1000, 1, 100, 0, 10}, 3, 2);
  Matrix matrix3 = Matrix::multiply(matrix1, matrix2);
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
