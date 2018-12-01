#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/input.h>
#include <linux/uinput.h>

#define die(str) do{perror(str);exit(EXIT_FAILURE);}while(0)

int main(int argc, char** argv) {
  int fd = open("/dev/input/event0",O_WRONLY);
  if (fd == 0) {
    printf("cant open /dev/input/event0");
  }
  return 0;
}
