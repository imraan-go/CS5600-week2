#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h> 
#include <fcntl.h>
int main(){
    int x = 100;
    close(STDOUT_FILENO);
    int fp = open("q2.output",O_CREAT | O_WRONLY | O_TRUNC,S_IRWXU);
    int rc =  fork();
    if (rc < 0 ){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if( rc == 0 ){
        // Child 
        x = 9;
        printf("Child value: %d \n",x);

    }else{
        //wait(&rc);
        printf("Parent value: %d \n",x);
        // Parent
    }
    return 0;
}

