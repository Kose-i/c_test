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

//#define die(str) do{perror(str);exit(EXIT_FAILURE);}while(0)
void die(const char* str)
{
  do{
    perror(str);
    exit(EXIT_FAILURE);
  }while(0);
}


int main(int argc, char** argv) {
  int ui_fd = open("/dev/input/event0",O_WRONLY);
  if (ui_fd < 0) die("error :open");

  if (ioctl(ui_fd, UI_DEV_DESTROY) < 0 ) die("error :ioctl");

  close(ui_fd);

  return 0;
}
