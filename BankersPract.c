#include <stdio.h>

int alloc[100][100];
int max[100][100];
int need[100][100];
int avail[100];

int main(){

int i,j,k,p,r;

printf("Enter no of process: \n" );
scanf("%d",&p );
printf("Enter no of resourses: \n" );
scanf("%d",&r );

printf("Enter Allocaion matrix: \n" );
for(i=0;i<p;i++){
  for(j=0;j<r;j++){
    scanf("%d",&alloc[i][j]);
  }
}
printf("Enter max matrix: \n" );
for(i=0;i<p;i++){
  for(j=0;j<r;j++){
    scanf("%d",&max[i][j]);
  }
}
printf("Enter available matrix: \n");

  for(j=0;j<r;j++){
    scanf("%d",&avail[j]);
  }

printf("Allocaion Matrix: \n");
for(i=0;i<p;i++){
  for(j=0;j<r;j++){
    printf("%d",alloc[i][j]);
  }
  printf("\n");
}
printf("max matrix: \n" );
for(i=0;i<p;i++){
  for(j=0;j<r;j++){
    printf("%d",max[i][j]);
  }
  printf("\n");
}
printf("available matrix: \n");

  for(j=0;j<r;j++){
    printf("%d",avail[j]);
  }
printf("\n");

int f[p],ans[p],ind=0,need[p][r];

for(i=0;i<p;i++){
  f[i]=0;
}
for(i=0;i<p;i++){
  for(j=0;j<r;j++){
    need[i][j]= max[i][j]-alloc[i][j];
  }
}
printf("Need Matrix: \n");
for(i=0;i<p;i++){
  for(j=0;j<r;j++){
    printf("%d",need[i][j]);
  }
  printf("\n");
}

int y,flag;
for(k=0;k<5;k++){
  for(i=0;i<p;i++){
      if(f[i]==0){

          flag = 0;
          for(j=0;j<r;j++){
            if(need[i][j]>avail[j])
            {
              flag = 1;
              break;
            }
          }

          if(flag==0){
            ans[ind++]=i;
            for(y=0;y<r;y++){
              avail[y]= avail[y]+alloc[i][y];
            }
            f[i]=1;
          }
      }
  }
}

flag = 1;
for(i=0;i<p;i++){
  if(f[i]==0){
    printf("it is not safe seq\n" );
    flag = 0;
    break;
  }
}
if(flag == 1){
  printf("it is safe seq\n" );
  for(i=0;i<p;i++){
    printf("p%d->",ans[i]);
  }
  
}


  return 0;
}
