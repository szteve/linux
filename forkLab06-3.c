#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
   pid_t pid;
   int tmp=10;  
   int status, exit_status;

if((pid = fork()) < 0) {
    perror("fork failed");
    exit(1);
  } 

  if(pid == 0) { /* child */
    printf("Child %d sleeping...\n", getpid());
    sleep(4);
    _exit(5); /* exit with non-zero value */
}

while (waitpid(pid, &status, WNOHANG) == 0){ /*Child still running*/
    printf("Still waiting...\n");
    sleep(1);
  }
  /* how did the child die? */
  if(WIFEXITED(status)) {
    exit_status = WEXITSTATUS(status);
    printf("Exit status from process %d = %d\n", pid, exit_status);
  }
  else if (WIFSIGNALED(status)) {
    exit_status = WTERMSIG(status);
    printf("Abnormal termination from process  %d = %d\n", pid, exit_status);
  }



   printf ("the main program process ID is: %d\n\n", getpid() );
   printf ( "Calling fork now\n\n");

   pid = fork();
   printf ( "fork has been called,  pid returned is: %d\n", pid);


   if( pid == 0)

   {

        printf("I am The child, PID is: %d\n", getpid() );
	 printf("I am The child, PPID is: %d\n", getppid() );
        printf("The return value from fork is: %d\n", pid);
        printf ( "The value of tmp is changed: %d \n\n", tmp*2);

   }

   else if ( pid > 0 )

   {
        printf ( "I am the parent, PID is: %d\n", getpid() );
        printf ( "I am the parent, PPID is: %d\n", getppid() );
	printf ( "The return value from fork is: %d\n", pid );
        printf ( "The value of tmp is: %d\n\n", tmp);
   }

   else
	printf("Forkfailed,nochild\n");
   return 0;
   exit(0); 
}

