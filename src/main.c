#include "pipex.h"

int main(int argc, char **argv)
{
    if (argc != 5)
    {
        ft_putstr_fd("Error: Usage -> ./pipex file1 cmd1 cmd2 file2\n", 2);
        return (EXIT_FAILURE);
    }
    if (!argv[2] || !argv[3])
    {
        ft_putstr_fd("Error: Invalid command arguments\n", 2);
        return (EXIT_FAILURE);
    }
    char *cmd1[] = {argv[2], NULL};
    char *cmd2[] = {argv[3], NULL};
    pipex(argv[1], cmd1, cmd2, argv[4]);
    return (EXIT_SUCCESS);
}