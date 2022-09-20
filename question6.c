#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h> 
int main(){
    int pid  =  getpid();
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc =  fork();
    
    if (rc < 0 ){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if( rc == 0 ){
        // Child 
        int status;
        int rt = waitpid(pid, &status, 0);
        printf("Hello, %d",status);
    }else{
        // Parent
        printf("%d",rc);
        int status;
        int rt = waitpid(-1, &status, 0);
       
        printf("Goodbye. Return value: %d",rc);
       
    }
    return 0;
}
