#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#define size 50
void main( int arg, char* arv[])
{
int file[2];
pid_t cid;
char buffer[size];
pipe(file);
if(arg!=3)
{
printf("Error- 3 parameters are required\n");
exit(1);
}
int f= open(arv[1],0);
int Target=open(arv[2],O_RDWR|O_CREAT|O_APPEND,0777);
if(f==-1||Target==-1)
{
printf("File cannot be opened\n");
exit(1);
}
cid=fork();
if(cid==0)
{
close(file[1]);
while(read (file[0],buffer,sizeof(buffer))>0)
{
        write(Target,buffer,strlen(buffer)-1);
}
close(file[0]);
close(Target);
}
else
{
close(file[0]);
while(read(f,buffer,sizeof(buffer))>0)
{
write(file[1],buffer,sizeof(buffer));
}
close(file[1]);
close(f);
wait(NULL);
}
}
