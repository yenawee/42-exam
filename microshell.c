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
	int	i = 1;
	t_pipelines *pipelines =	NULL;

	if (argc < 2)
		exit(1);
	//tokenize
	while (argv[i])
	{
		t_token *new = malloc(sizeof(t_token));
		if (!new)
			err_fatal();
		new->str = ft_strdup(argv[i]);
		if (strcmp(argv[i], ";") == 0)
			new->type = T_BREAK;
		else if (strcmp(argv[i], "|") == 0)
			new->type = T_PIPE;
		else
			new->type = T_WORD;
		ft_lst_add_back(&token, new);
		i++;
	}	

	//pipelines
	t_token *tmp = token;
	pipelines = malloc(sizeof(t_pipelines));
	if (!pipelines)
		err_fatal();
	pipelines->token_size = 0;
	pipelines->seperate_type = 0;
	t_pipelines *cur_pipeline = pipelines;
	while (1)
	{
		if (tmp == NULL || tmp->type == T_BREAK)
		{
			cur_pipeline->tokens = token;
			if (tmp == NULL)
				break ;
			pipelines->seperate_type = T_BREAK;
			cur_pipeline->next =  malloc(sizeof(t_pipelines));
			if (!cur_pipeline->next)
				err_fatal();
			cur_pipeline = cur_pipeline->next;
			token = tmp->next;
			tmp = tmp->next;
			continue ;
		}
		cur_pipeline->token_size++;
		tmp = tmp->next;		
	}

	// while (pipelines)
	// {
	// 	t_token *token = pipelines->tokens;
	// 	printf("type %d\n", pipelines->seperate_type);
	// 	printf("tokens :  \n");
	// 	int n = pipelines->token_size;
	// 	while (n--)
	// 	{
	// 		printf("%s\n", token->str);
	// 		token = token->next;
	// 	}
	// 	pipelines = pipelines->next;
	// }

	//command

}
