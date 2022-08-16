#include "microshell.h"

int	_excute(t_token *tokens, char **envp)
{
	pid_t	pid;

	if (tokens->type == T_PIPE)
		if (pipe(tokens->fd))
			err_fatal();
	pid = fork();
	if (pid < 0)
		err_fatal();
	else if (pid == 0)
	{
		if (tokens->type == T_PIPE)
			if (dup2(tokens->fd[1], STDOUT) == -1)
				err_fatal();
		if (tokens->prev && tokens->prev->type == T_PIPE)
			if (dup2(tokens->prev->fd[0], STDIN) == -1)
				err_fatal();
		if (execve(tokens->str[0], tokens->str, envp) == -1)
			err_execve(tokens->str[0]);
	}
	else
	{
		waitpid(pid, 0, 0);
		if (tokens->type == T_PIPE)
			close(tokens->fd[1]);
		if (tokens->prev && tokens->prev->type == T_PIPE)
			close(tokens->prev->fd[0]);
	}
	return (EXIT_SUCCESS);
}

int	ft_cd(t_token *tokens)
{
	if (tokens->size < 2)
		err_cd_arg();
	if (chdir(tokens->str[1]) == -1)
		err_cd(tokens->str[1]);
	return (EXIT_SUCCESS);
}

int	excute(t_token *tokens, char **envp)
{
	int	ret = EXIT_SUCCESS;
	while (tokens)
	{
		if (strcmp(tokens->str[0], "cd") == 0)
			ret = ft_cd(tokens);
		else
			ret = _excute(tokens, envp);
		tokens = tokens->next;
	}
	return (ret);
}
