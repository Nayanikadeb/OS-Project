#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
void main()
{
int a=0;
int b;
pid_t pid;
printf("Enter the  number\n");
scanf("%d",&b);
do{
if(b<=0)
printf("Invalid Input. Please enter a positive number");
}while(b<=0);
pid=fork();
if(pid==0)
{
printf("\nChild process is working \n");
 printf("%d \n",b);
while(b!=1)
{
        if(b%2==0)
        b=b/2;
        else if(b%2==1)
        b=3*(b)+1;

printf("%d \n",b);

}                        
printf("\n Child Process is completed\n");
}

else
{
printf("\nParent process waiting for child process\n");
wait(NULL);
printf("\n Parent process is completed\n");
}
}
