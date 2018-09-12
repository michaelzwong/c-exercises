#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("hello world (pid:%d)\n", (int) getpid());
  int status;
  int rc = fork();
  if (rc < 0) { // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) { // child
    printf("hello, I am child (pid:%d)\n", (int) getpid());
  } else {
    // Parent calls wait to delay its execution
    // until child is done.
    // This guarantees child prints first.
    int rc_wait = wait(&status);
    printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait,
     (int) getpid());
  }
  return 0;
}
