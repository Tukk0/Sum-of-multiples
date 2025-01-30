#include <iostream>
#include <stdlib.h>

using std::atoi;
using std::cin;
using std::cout;

bool dif (int* array, int size) {
  for (int i = 0; i < size - 1; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (array[i] == array[j]) {
        return false;
      }
    }
  }
  return true;
}

int main(int arrs, char** argv) {
  --arrs;
  int* lengths = new int[arrs];
  int** arrays = new int*[arrs];
  for (int i = 0; i < arrs; ++i) {
    lengths[i] = atoi(argv[i + 1]);
  };
  for (int i = 0; i < arrs; ++i) {
    arrays[i] = new int[lengths[i]];
    for (int j = 0; j < lengths[i]; ++j) {
      cin >> arrays[i][j];
    }
  }
  int* indices = new int[arrs];
  for (int i = 0; i < arrs; ++i) {
    indices[i] = 0;
  }
  int combinations = 1;
  for (int i = 0; i < arrs; ++i) {
    combinations *= lengths[i];
  }
  int sum = 0;
  for (int i = 0; i < combinations; ++i) {
    int product = 1;
    if (dif(indices, arrs)) {
      for (int j = 0; j < arrs; ++j) {
        product *= arrays[j][indices[j]];
      }
      sum += product;
    }
      ++indices[0];
      for (int j = 0; j < arrs; ++j) {
        if (indices[j] >= lengths[j]) {
          indices[j] = 0;
          if (j < arrs - 1) {
            ++indices[j + 1];
          }
        }
      }
  }
  cout << sum << "\n";
  delete[] lengths;
  delete[] indices;
  for (int i = 0; i < arrs; ++i) {
    delete[] arrays[i];
  }
  delete[] arrays;
  return 0;
}
