#include <stdio.h>

#define char_bit_size 8
void display_bit_char(char t) {
  char tmp = 1;
  char str[char_bit_size];
  for (int i = 0;tmp != 0;tmp = tmp<<1, ++i) {
    str[i] = ((tmp&t) > 0)?'1':'0';
  }
  for (int i = char_bit_size - 1;0 <= i;--i) {
    printf("%c", str[i]);
  }
  printf("\n");
}
int main(int argc, char** argv)
{
  display_bit_char(3);
}
