// C program to illustrate
// pipe system call in C
#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>

int basic(void)
{
    int pipefds[2];

    if (pipe(pipefds) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    printf("Read File Descriptor Value: %d\n", pipefds[0]);
    printf("Write File Descriptor Value: %d\n", pipefds[1]);

    return EXIT_SUCCESS;
}

int read_write_eg(void)
{
    int pipefds[2];
    char buffer[5];

    if (pipe(pipefds) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    char *pin = "4128\0";

    printf("Writing PIN to pipe...\n");
    write(pipefds[1], pin, 5);
    printf("Done.\n\n");

    printf("Reading PIN from pipe...\n");
    read(pipefds[0], buffer, 5);
    printf("Done.\n\n");

    printf("PIN from pipe: %s\n", buffer);

    return EXIT_SUCCESS;
}
void main()
{
    read_write_eg();
}