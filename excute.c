#include "microshell.h"

int	_excute(t_token *tokens, char **envp)
{
	int	ret;

	// pipe

	// fork

	// execve

	// wait

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
