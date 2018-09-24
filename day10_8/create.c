/*
 * create process
 */
#include<stdio.h>
#include<unistd.h>
int main()
{
     pid_t pid = fork();
     if(pid<0)
     {
	printf("error\n");
	return -1;
     }
     else if(pid == 0)
     {
	printf("this is child %d\n",getpid());
     }
     else 
     {		
	printf("this is parent %d child  %d\n",getpid(),pid);
     }
     printf("%d\n",pid);
     while(1)
     {
	sleep(1);
     } 	
     return 0;  
}
