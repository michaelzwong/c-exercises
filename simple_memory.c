#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int *p = (int*) malloc(sizeof(int));
  printf("(%d) Address pointed to by p: %p\n", getpid(), p);
  *p = 0;
  while(1) {
    sleep(1);
    *p = *p + 1; // update value at memory
    printf("(%d) p: %d\n", getpid(), *p);
  }
  return 0;
}
