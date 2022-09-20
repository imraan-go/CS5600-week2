#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h> 
int main(){
    int rc =  fork();
    if (rc < 0 ){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if( rc == 0 ){
        // Child 
        close(STDOUT_FILENO);
        printf("Hello\n");
    }else{
        // Parent
        // printf("%d",rc);
        // int rt = wait(NULL);
        wait(NULL);
        printf("Goodbye. Return value: %d",9);
       
    }
    return 0;
}

