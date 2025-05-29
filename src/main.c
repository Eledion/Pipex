#include "pipex.h"

int main(int argc, char **argv)
{
    if (argc != 5)
    {
        ft_putstr_fd("Use: ./pipex <file1 comand1 comand2 file2\n", 1);
        return (1);
    }

    char *cmd1[] = {argv[2], NULL};
    char *cmd2[] = {argv[3], NULL};

    pipex(argv[1], cmd1, cmd2, argv[4]);
    return (0);
}