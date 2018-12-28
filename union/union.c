union tmp{
  int a;
  char t;
};

#include <stdio.h>

struct Tmp{
  union tmp union_tmp;
  int tmp_is_int;
};
int main(int argc, char** argv)
{
  union tmp t;
  t.a = 3;
  printf("%lu", sizeof(t));
  printf("%c",t.t);//意図しない結果となる
}
