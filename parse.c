#include "microshell.h"

int add_arg(t_token *tokens, char *arg)
{
	char    **tmp;
	tokens->size++;
	tmp = malloc(sizeof(char *) * (tokens->size + 1));
	if (!tmp)
		err_fatal();
	int i = 0;
	while (i < tokens->size - 1)
	{
		tmp[i] = tokens->str[i];
		i++;
	}
	if (tokens->str)
		free(tokens->str);
	tokens->str = tmp;
	tokens->str[i++] = ft_strdup(arg);
	tokens->str[i] = NULL;
	return (EXIT_SUCCESS);
}

int ft_lst_addback(t_token **tokens, char *arg)
{
	t_token *new = malloc(sizeof(t_token));


	if (!new)
		err_fatal();
	new->type = T_WORD;
	new->size = 0;
	new->str = NULL;
	new->next= NULL;
	new->prev = NULL;
	if (*tokens)
	{
		(*tokens)->next = new;
		new->prev = *tokens;
	}
	*tokens = new;
	return (add_arg(*tokens, arg));
}



int parse(t_token **tokens, char *arg)
{
	int is_break = (strcmp(arg, ";") == 0);
	int is_pipe = (strcmp(arg, "|") == 0);

	if (is_break && !(*tokens))
		return (EXIT_SUCCESS);
	if (!is_break && (!(*tokens) || (*tokens)->type > 1))
		return (ft_lst_addback(tokens, arg));
	if (is_break)
		(*tokens)->type = T_BREAK;
	else if (is_pipe)
		(*tokens)->type = T_PIPE;
	else
		return (add_arg(*tokens, arg));
	return (EXIT_SUCCESS);
}
