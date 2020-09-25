# include  <stdio.h>  
# include <string.h>  
# include <sys/types.h>  
# include <stdlib.h>  
void main ( void ){  
 int pid;  
 int i;  
 srand ( time ( NULL ));  
 for (i = 0 ; i < 2 ;++i){  
 pid = fork ();  
 if (pid == 0 ){  
 int x = ( rand () % 30 ) + 1 ;  
 int y = ( rand () % 10 ) + 1 ;  
 int i;  
 for (i = 0 ; i < x; i++){  
 printf ( "Child PID: %d is going to sleep!\n" , getpid ());   sleep (y);  
 printf ( "Child %d : I'm awake!\n Where is my Parent  
%d ?\n" , getpid (), getppid ());  
 }  
 exit ( 0 );  
 }  
 else if (pid > 0 ){  
 int status = wait (&status); 
 printf ( "Child Pid: %d has completed!\n" ,status);   }  
 else {  
 printf ( "something is wrong!" );  
 exit ( 0 );  
 }  
 }  
} 
