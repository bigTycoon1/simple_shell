#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
/**
 * main - PID
 *
 * Return: Always 0.
 */

int main() 
{
    pid_t p_pid = getppid();
    printf("P PID: %u\n", p_pid);

    return 0;
}
