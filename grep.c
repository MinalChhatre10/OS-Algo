#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

char fn[10],temp[100],pat[10];
int result=0;
FILE *fp;
printf("Enter file name\n");
scanf("%s", fn);
printf("Enter pattern\n");
scanf("%s", pat);
fp=fopen(fn,"r");
if(fp==NULL){
  printf("Cant open file\n" );
  exit(0);
}
while(fgets(temp,1000,fp)!=NULL){
  if(strstr(temp,pat)){
    printf("%s\n",temp );
    result++;
  }
}
if(result==0){
  printf("no pattern found\n" );
}


  return 0;
}
