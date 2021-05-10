#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>


int main(void){
    //neves�tett pipe l�trehoz�sa
	char * myfifo = "/tmp/myfifo";
	mkfifo(myfifo, 0666);
	int fd;
	char buf[20];
	pid_t p;
	//parent&child l�trehoz�sa
	p=fork();

	if(p<0)
	{
		fprintf(stderr, "fork Failed");
		return 1;
	}
	//parent
	else if(p > 0)
	{
		//a buf string �rt�ket kap a pipebol
		fd = open(myfifo, O_RDONLY);
		read(fd, buf, 20);
		int opening = 0;
		//f�jlki�r�s
		if((opening=open("kimenet.txt", O_RDWR)) < 0){
			printf("Nincs ilyen fajl!\n");
			return -1;
		}
		write(opening, buf, strlen(buf)+1);
		close(opening);
		close(fd);
	}
	//child
	else
	{
		char bemenetSor[10];
		int opening = 0;
		//f�jlb�l beolvas�s
		if((opening=open("bemenet.txt", O_RDWR)) < 0){
			printf("Nincs ilyen fajl!\n");
			return -1;
		}

		int bemenetMeret = read(opening, bemenetSor, sizeof(bemenetSor));
		bemenetSor[bemenetMeret] = '\0';
		//a,b,c oldal �rt�kad�sa a bemenet els� sor�b�l
		int a = bemenetSor[0] - '0';
		int b = bemenetSor[2] - '0';
		int c = bemenetSor[4] - '0';

		char pipeUzenet[10];
		//string felt�lt�se ami a pipeba megy
		pipeUzenet[0] = bemenetSor[0];
		pipeUzenet[1] = ' ';
		pipeUzenet[2] = bemenetSor[2];
		pipeUzenet[3] = ' ';
		pipeUzenet[4] = bemenetSor[4];
		pipeUzenet[5] = ' ';
		//1 == szerkeszhet�, 0 == nem szerkeszthet�
		if( (a + b > c) && (b + c > a) && (c + a > b) )
			pipeUzenet[6] = '1';
		else
			pipeUzenet[6] = '0';
		pipeUzenet[7] = '\0';

		fd = open(myfifo, O_WRONLY);
		//pipeba bek�ld�s
		write(fd, pipeUzenet, strlen(pipeUzenet)+1);
		close(opening);
		close(fd);

	}
	//a pipe t�rl�se
	unlink(myfifo);
	return 0;

}

