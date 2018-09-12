#include <stdio.h>

void find_largest_in_array(int *A_array, int A_array_size, int *largest_pt) {
  *largest_pt = *A_array; // A[0]
  for (int i = 0; i < A_array_size; i++) {
    if(A_array[i] > *largest_pt) {
      *largest_pt = A_array[i];
    }
  }
}

void find_largest_in_ptr_array(int **A_array, int A_array_size, int *largest_pt) {
  *largest_pt = **A_array; // A[0]
  for (int i = 0; i < A_array_size; i++) {
    if(*A_array[i] > *largest_pt) {
      *largest_pt = *A_array[i];
    }
  }
}

int main() {
  int i = 90;
  int j = -4;
  int k = 69;
  int l = 32;

  int A_array[4] = {i, j, k, l};

  int *A_ptr_array[4] = {&i, &j, &k, &l};

  int largest;

  int largest_ptr;

  int A_array_size = (int) (sizeof(A_array)/sizeof(A_array[0]));

  find_largest_in_array(A_array, A_array_size, &largest);

  find_largest_in_ptr_array(A_ptr_array, A_array_size, &largest_ptr);

  printf("Option 1 - Largest is %d\n", largest);

  printf("Option 2 - Largest is %d\n", largest);


  return 0;

}
