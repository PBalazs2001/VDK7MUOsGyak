#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>



void nothing();
int main(){

    unsigned sec = 1;
    signal(SIGALRM, semmi);
    alarm(sec);


    printf("%d I'm waiting.\n",1);
    pause();

    printf("An alarm has been received.\n");

 return 0;
}


void nothing(){
;
}
