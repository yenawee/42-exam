#include "microshell.h"

void	ft_lst_add_back(t_token **token, t_token *new)
{
	t_token *tmp;

	if (*token == NULL)
	{
		*token = new;
		return ;
	}
	tmp = *token;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	return ;
}


int main(int argc, char **argv, char **envp)
{
	t_token *token;
	int	i = 0;

	if (argc < 2)
		exit(1);
	//tokenize
	while (argv[i])
	{
		t_token *new = malloc(sizeof(t_token));
		if (!new)
			err_fatal();


		i++;
	}
	//pipelines
	//command

}
