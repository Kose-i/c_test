#include <stdio.h>

struct parson{
  char* name;
  unsigned int old;
};

typedef struct Tmp{
  int tm;
}Tmp;

int main(int argc, char** argv)
{
  struct parson kosei;
  kosei.name = "tamura";
  kosei.old = 19;
  Tmp tmp;
}
