#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

 int main() {
  FILE *s,*t;
  char ch;
  s= fopen("minal.txt","r");
  t = fopen("chhatre.txt","w");
  while((ch=fgetc(s))!=EOF){
    fputc(ch,t);
  }
  fclose(s);
  fclose(t);
  printf("File copied successfully\n");
  return 0;
}
