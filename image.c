#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>


int main(){
  char * store = (char *) malloc(25);
  int fd = open("firstimage.ppm", O_CREAT | O_WRONLY | O_TRUNC, 0644 );
  sprintf(store, "P3 500 500 255\n");
  write(fd,store, strlen(store));
  int i, f, r, g, b, bonus;
  r = 0;
  g = 0;
  b = 0;
  bonus = 0;
  for(i = 0; i < 500; i ++){
    for(f = 0; f < 500; f ++){
      if(f >= 250 - bonus && f <= 250 + bonus){
	r = 0;
	g = 0;
	b = 255;
      }
      else{
	r = 245;
	g = 120;
	b = 11;
      }
      sprintf(store, "%d %d %d ", r,g,b);
      write(fd,store,strlen(store));
    }
    if(i <= 250){
      bonus ++;
    }
    else{
      bonus --;
    }
  }
  close(fd);
  return 0; 
}
