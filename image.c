#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>


int main(){
  int fd = open("firstimage.ppm", O_CREAT | O_WRONLY, 0644 );
  write(fd, "P3 500 500 255\n", 15);
  int i = 0;
  int f = 0;
  while(i < 500){
    while(f < 500){
      write(fd,"33",2);
      write(fd,"94",2);
      write(fd,"200",2);
      f ++;
    }
    i ++;
  }
  close(fd);
  return 0; 
}
