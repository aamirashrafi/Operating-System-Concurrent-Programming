#include <stdio.h>
#include <stdlib.h>

int
main(){
  sleep(5);
  printf("PID: %d, Parent PID: %d\n",getpid(), getppid());
  exit(10);
}
