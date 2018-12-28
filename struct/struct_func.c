#include <stdio.h>

void t_print(int a) {
  printf("%d\n", a);
}

typedef struct Tmp{
  void (*print)(int);
}Tmp;

int main(int argc, char** argv) {
  Tmp t;
  t.print = t_print;
  t.print(3);
}
