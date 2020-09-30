#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#define MAX 2
void main(int argc, char *argv[]){
  int pid[MAX];
	int status;
	int x;
  int mAx;

	for(x=0;x<MAX;x++){

		pid[x] = fork(); //fork creates a child

		switch(pid[x]) {
			case 0:		//child
        mAx = 30;
        //srand(1);
        for(x=0;x< (random() % mAx);x++){
          printf("Child pid is going to sleep!\n");
          sleep(random()% 10);	
        }
				printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n",getpid(),getppid());
				exit(0);
			case -1:	//error
				break;

			default:	//parent, PID is child pid
        break;
		}	

	}
  for(x=0;x<MAX;x++){
    printf("Child Pid: %d has completed...\n",pid[x]);
    wait(&status); //parent wait until child terminates, then reaps child
  }
	printf("Parent Terminating : Child status = %d\n",status);

}
