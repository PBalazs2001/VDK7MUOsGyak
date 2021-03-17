#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int system(const char *command);
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    char command[10];
	char kilepes[2];
	strcpy(kilepes,"/");
	int ok;
	do{
		ok = 0;
		printf("Add meg parancsot(date, pwd, who etc.): ");
		scanf("%s", command);
		if(strcmp(command, kilepes) == 0)
			return 0;
		system(command);
	}while(!ok);
	return 0;
}
