#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>


int main(){
  char * store = malloc(sizeof(char *));
  int fd = open("firstimage.ppm", O_CREAT | O_WRONLY | O_TRUNC, 0644 );
  sprintf(store, "P3 750 750 255\n");
  write(fd,store, strlen(store));
  int i, f, r, g, b;
  i = 0;
  f = 0;
  r = 0;
  g = 0;
  b = 0;
  while(i < 750){
    while(f < 750){
      r = 245;
      g = 120;
      b = 11;
      sprintf(store, "%d %d %d\n", r,g,b);
      write(fd,store,strlen(store));
      f ++;
    }
    i ++;
  }
  close(fd);
  return 0; 
}
