#include <stdio.h>

int print(int a){
  printf("test\n");
  return 4;
}

struct test{
  int (*tre)(int);
};
//int test.tre(int global) {
//  return global;
//}


int main(int argc, char** argv) {
  struct test t;
  t.tre = print;
  printf("%d\n", t.tre(3));
}
