#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>


int main(int argc , char *argv[]){
if(argc<2){
fprintf(stderr,"Please enter number of level you want.");
}

int n;
n=atoi(argv[1]);
int arr[n-1];
int i;
printf("parent id is %d\n",getpid());
for(i=0;i<=n-1;i++){
    arr[i]=getpid();
    if((i+1)%2!=0){
        if(fork()!=0){
            break;
        }

    }
    else if((i+1)%2==0){
    int check1;
    int check2;
    check1=fork();
    if(check1!=0){
        check2=fork();
        if(check2!=0){
        break;
        }
       }
    }
    if(i==n-1){
         int j;
         printf("\nProcess : ");
         for(j=0;j<n;j++){
             printf("\t %d",arr[j]);
         }
         printf("\n");

    }
}

return 0;
}
