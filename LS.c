#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

void LSfunc(){
  char directname[10];
  DIR *p;
  struct dirent *d;
  printf("Enter the directory name: \n");
  scanf("%s",directname );
  p=opendir(directname);
  if(p==NULL){
    printf("Cant open the directory\n" );
    exit(0);
  }
  while(d=readdir(p)){
    printf("%s\n", d->d_name);
  }

}

int main(){

LSfunc();


  return 0;
}
