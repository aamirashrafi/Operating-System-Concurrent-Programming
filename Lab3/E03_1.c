#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc , char *argv[]){
if(argc<2){
fprintf(stderr,"Please enter number of level you want.");
}
int n;
n=atoi(argv[1]);
int i;
printf("parent id is %d\n",getpid());
for(i=1;i<=n;i++){
    if(i%2==0){
    //printf("i : %d, Double fork\n",i);
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
    else if(i%2!=0){
    //printf("i : %d, Single fork\n",i);
        if(fork()!=0){
            break;
        }

    }
    if(i==n-1){
        printf("Process %d \n",getpid());
    }

   // }/**/
}

//exit(0);

return 0;
}
