#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>

int main(void){
	int fd1;
	char buf[20];
	pid_t p;
	p=fork();
	if(p<0)
	{
		fprintf(stderr, "fork Failed");
		return 1;
	}
	//parent
	else if(p > 0)
	{
		fd1 = open("VDK7MU", O_RDONLY);
		read(fd1, buf, 20);
		printf("2. feladat: %s\n", buf);
		close(fd1);
	}
	//child
	else
	{
		char name[] = "Pércsi Balázs";
		fd1 = open("VDK7MU", O_WRONLY);
		write(fd1, name, strlen(name)+1);
		close(fd1);

	}

}
