#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

void main(){
  struct stat s;
  stat("Status.c",&s);
  printf("Size of program: %ld\n",s.st_size);
  printf("Device id: %ld\n",s.st_dev);
  printf("File last accessed : %s",ctime(&s.st_atime));
  printf("Modified: %s",ctime(&s.st_mtime));
}
