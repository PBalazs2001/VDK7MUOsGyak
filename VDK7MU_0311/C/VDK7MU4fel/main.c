#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main (){

        pid_t pid;
        if ((pid = fork()) < 0)
        {
            perror("Hiba");
        }
        else if (pid == 0)
        {
            if(execl("/bin/ls", "ls", "-la",NULL)
            {
                perror("execl hiba");
            }
        }
        if (waitpid(pid, NULL, 0) < 0)
        {
            perror("wait hiba");
        }
        return 0;
}
