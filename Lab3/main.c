#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc , char *argv[]){
    int n;
    int i;
    int check1;
    int check2;
    pid_t ppid;

    if(argc<2){
        fprintf(stderr,"\nUsage: <%s> <number of level>\n\n",argv[0]);
        return -1;
    }

    n=atoi(argv[1]);

    ppid = getpid();
    printf("\nparent id is %d\n",ppid);
    for(i=1;i<=n;i++){
        if(i%2==0){
            check1=fork();
            if(check1!=0){
                check2=fork();
                if(check2!=0)
                    break;
            }
        }else{
            if(fork()!=0)
              break;
        }
    }

    printf("\nProcess %d \n",getpid());

    exit(0);

}
