#include <stdio.h>

#define test(str) # str

int main(int argc, char** argv)
{
  int a_rt = 3;
  puts(test(a_rt));
}
