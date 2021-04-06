#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#define SECOND 1

void do_nothing();
void do_int();


int main(){

    int i;
    unsigned sec = 1;
    signal(SIGINT, int_erkezik);
    for(i = 1; i < 8; i++)
    {
        alarm(sec);
        signal(SIGALRM, semmi);
        printf("%d\n", i);
        pause();
    }
    return 0;
}



void nothing(){;}
void int_erkezik()
{
        printf("int megjott.\n");
        signal(SIGINT, SIG_IGN);
}
