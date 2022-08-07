#include "microshell.h"

void	err_fatal()
{
	write(2, "error: fatal\n", ft_strlen("error: fatal\n"));
	exit(EXIT_FAILURE);
}

void	err_execve(char *str)
{
	write(2, "error: cannot execute ", ft_strlen("error: cannot execute "));
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	err_cd_arg()
{
	write(2, "error: cd: bad arguments\n", ft_strlen("error: cd: bad arguments\n"));
	exit(EXIT_FAILURE);
}

void	err_cd(char *str)
{
	write(2, "error: cd: cannot change directory to ", ft_strlen("error: cd: cannot change directory to "));
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
