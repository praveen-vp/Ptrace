#include <sys/ptrace.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
main()
{
    int pid, status;
    if((pid = fork()) == 0) {
        ptrace(PTRACE_TRACEME, 0, 0, 0);
        execl("/home/praveen/Working-Directory/Linux/Ptrace", "child2", 0);
        printf("exec failed...\n");
    } else {
        wait(&status);
        if(WIFSTOPPED(status))
            printf("child has stopped...\n");
        sleep(10);
        ptrace(PTRACE_CONT, pid, 0, 0);
        wait(&status);
    }
}
        
