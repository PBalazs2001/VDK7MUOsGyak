#include <stdio.h>
#include <stdlib.h>
int system(const char *command);
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int status;
    if((status = system("date"))<)
    {
        perror("system() error");
    }
    if(WIFEEXITED(status))
    {
        printf("Normalis befejezes visszaadott ertek: %d\n"; WEXITSTATUS(status));
    }
    exit(0);
    return 0;
}
