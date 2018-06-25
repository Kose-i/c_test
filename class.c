#include <stdio.h>

void print(){
  printf("test");
}

struct test{
  void test = print;
};


int main(int argc, char** argv) {
  struct test t;
}
