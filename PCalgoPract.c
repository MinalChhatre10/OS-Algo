#include <stdio.h>
#include <stdlib.h>

int mutex=1,p=0,c=0,empty=3,full=0;
int wait(int s){
  return --s;
}
int signal(int s){
  return ++s;
}
void producer(){
  mutex = wait(mutex);
  full = signal(full);
  empty = wait(empty);
  p++;
  printf("producer produced %d \n",p);
  mutex = signal(mutex);
}

void consumer(){
  mutex = wait(mutex);
  empty = signal(empty);
  full = wait(full);
  c++;
  printf("consumer consumed %d \n",c);
  mutex = signal(mutex);
}

int main(){
void producer();
void consumer();
int wait(int);
int signal(int);
int n,i,j;
while(1){
  printf("1.producer 2.consumer 3.exit\n");
  printf("Enter your choice : \n" );
  scanf("%d",&n);
  switch(n){
    case 1:
    if(mutex==1&&empty!=0){
      producer();
    }
    else{
      printf("buffer is full\n" );
    }

    break;
    case 2:
    if(mutex==1&&full!=0){
        consumer();
    }
    else{
      printf("buffer is empty\n" );
    }

    break;
    case 3:
    exit(0);
    break;
  }
}


  return 0;
}
