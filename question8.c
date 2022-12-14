#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#define BUFSZE 32



int
main(int argc, char *argv[])
{
    // Setup our pipe
    char buff[BUFSZE];
    int p[2];

    if (pipe(p) < 0)
      exit(1);

    int rc1 = fork();
    if (rc1 < 0) {
        // fork failed; exit
        fprintf(stderr, "fork #1 failed\n");
        exit(1);
    } else if (rc1 == 0) {
	     // Child #1
       printf(" Child #1 ");
       close(p[0]);   // This one only writes
       dup2(p[1], 1); // redirect stdout to pipe write
       printf("_This is getting sent to the pipe_");
    } else {
        // Parent process
        int rc2 = fork();
        if (rc2 < 0) {
          fprintf(stderr, "fork #2 failed\n");
          exit(1);
        } else if (rc2 == 0) {
          // Child #2
          printf(" Child #2 ");
          close(p[1]);      // Only read here
          dup2(p[0], 0);    // Redirect stdin to pipe read

          

          char buff[512];   // Make a buffer
          read(STDIN_FILENO, buff, 512); // Read in from stdin
          printf("%s", buff);     // Print out buffer

        } else {
          // Initial parent process


          int wc = waitpid(rc2, NULL, 0);
          printf("goodbye");
        }
    }
    return 0;
}