#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
int main(){
    int rc =  fork();
    if (rc < 0 ){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }else if( rc == 0 ){
        // Child 

        // execvp
        // char *args[]={"ls",NULL};
        // execvp(args[0],args);
        // execv
        char *args2[]={"/usr/bin/printenv",NULL};
        char *envp[]={"TEST=123",NULL};
        execve(args2[0],args2,envp);

    }else{
        // Parent
        wait(&rc);
        printf("Goodbye");
       
    }
    return 0;
}

