#include<stdio.h>
#include<unistd.h>

int main()
{
   pid_t pid;
   int tmp=10;

   printf ("the main program process ID is: %d\n\n", getpid() );
   printf ( "Calling fork now\n\n");

   pid = fork();
   printf ( "fork has been called,  pid returned is: %d\n", pid);


   if( pid == 0)

   {
	printf("I am the child im running\n");
        printf("I am The child, PID is: %d\n", getpid() );
         printf("I am The child, PPID is: %d\n", getppid() );
        printf("The return value from fork is: %d\n", pid);
        printf ( "The value of tmp is changed: %d \n\n", tmp*2);

   }

   else if ( pid > 0 )

   {
	printf("I am the parent i am running\n");
        printf ( "I am the parent, PID is: %d\n", getpid() );
        printf ( "I am the parent, PPID is: %d\n", getppid() );
        printf ( "The return value from fork is: %d\n", pid );
        printf ( "The value of tmp is: %d\n\n", tmp);
   }

     else

        printf ( "Fork failed, no child\n" );

   return 0;
}


