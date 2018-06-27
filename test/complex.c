#include <stdio.h>
#include <math.h>

struct My_complex{
  double real;
  double img;
  double (*complex_size)(double real, double img);
};

double comp_size(double real, double img) {
  return (sqrt(pow(real, 2) + pow(img, 2)));
}

int main(int argc, char** argv){
  struct My_complex t;
  t.complex_size = comp_size;
  t.real = 2;
  t.img = 3;
  printf("%lf", t.complex_size(t.real, t.img));
}
