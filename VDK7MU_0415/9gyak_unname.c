#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <string.h>

#define MSGSIZE 30

int main (void){
	int v9rn7c[2];
	char inbuf[50];
	pipe(v9rn7c);
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
		read(v9rn7c[0], inbuf, MSGSIZE);
		printf("1. feladat: %s\n", inbuf);
	}
	//child
	else
	{
		char name[] = "Pércsi Balázs VDK7MU";
		write(v9rn7c[1], name, strlen(name));
	}
}
