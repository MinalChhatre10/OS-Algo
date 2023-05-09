#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>


int main(){

  char dirname[10];
  struct dirent **namelist;
  int n;
  printf("Enter directory name: \n" );
  scanf("%s", dirname);

  n= scandir(dirname,&namelist,NULL,alphasort);
  if(n==-1){
    printf("Cant open directory\n" );
    exit(0);
  }
  for(int i=0;i<n;i++){
    printf("%s\n",namelist[i]->d_name );
    free(namelist[i]);
  }
  free(namelist);
  return 0;

}
