#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void interrupt(int sign);
void quit(int sign);
unsigned int rupts = 0;

int main(void)
{
    if (signal(SIGINT, interrupt) == SIG_ERR)
    {
        printf("Failed to assign handler to SIGINT!\n");
        return 0;
    }

     if (signal(SIGQUIT, quit) == SIG_ERR)
    {
        printf("Failed to assign handler to SIGQUIT!\n");
        return 0;
    }

    while(rupts < 2)
    {
        printf("Waiting for the sign...\n");
        sleep(1);
    }

    printf("We have the second SIGINT signal!");
    return 0;
}

void interrupt(int sign)
{
    printf("SIGINT sign: %d\n", sign);
    rupts++;
}

void quit(int sign)
{
    printf("SIGQUIT sign: %d\n", sign);
}
