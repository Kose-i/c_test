#include <stdio.h>

typedef struct Tmp{
  char c_1;
  int i_1;
  char c_2;
  int i_2;
}Tmp;

int main(int argc, char** argv) {
  Tmp tmp;
  printf("tmp.c_1:%p\n", &tmp.c_1);
  printf("tmp.i_1:%p\n", &tmp.i_1);
  printf("tmp.c_2:%p\n", &tmp.c_2);
  printf("tmp.i_2:%p\n", &tmp.i_2);
}
