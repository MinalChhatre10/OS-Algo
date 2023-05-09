#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
pthread_t tid[2];

void *doFunc(void *arg){
  unsigned long i=0;
  pthread_t id = pthread_self();
  if(pthread_equal(id,tid[0])){
    printf("first thread \n");
  }
  else{
      printf("Second thread \n");
  }
  for(i=0;i<0xffffffff;i++);
  return NULL;
}


int main(void){
int i=0;
int err;
while(i<2){
  err = pthread_create(&tid[i],NULL,&doFunc,NULL);
  if(err!=0){
    printf("thread not created \n");
  }
  else{
    printf("thread created successfully \n");
  }
i++;

}
  sleep(5);
  return 0;
}
