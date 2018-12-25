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

void die(const char* str)
{
  do{
    perror(str);
    exit(EXIT_FAILURE);
  }while(0);
}


int main(int argc, char** argv) {
  int ui_fd = open("/dev/input/mouse0",O_RDONLY | O_NONBLOCK);
  if (ui_fd < 0) die("error :open");

  struct input_event ui_struct;
  char buff[100 + 1];

  for(;;){
    if(read(ui_fd, buff, 100 < 0)) die("error :read");
    printf("%d %d %d",ui_struct.type , ui_struct.code, ui_struct.value);

  }

  if (ioctl(ui_fd, UI_DEV_DESTROY) < 0 ) die("error :ioctl");

  close(ui_fd);

  return 0;
}
