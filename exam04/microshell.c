#include "microshell.h"

int _token(t_token **tokens)
{
	while (*tokens && (*tokens)->prev)
		*tokens = (*tokens)->prev;
	return 0;
}

int main(int argc, char **argv, char **envp)
{
	t_token *tokens;
	t_token *tmp;


	int i = 1;
	tokens = NULL;
	while (i < argc)
		parse(&tokens, argv[i++]);
	_token(&tokens);
	int ret  = excute(tokens, envp);
	// while (tokens)
	// {
	// 	for (int i = 0; i < tokens->size - 1; i++)
	// 		printf("%s\n", tokens->str[i]);
	// 	printf("type %d\n", tokens->type);
	// 	printf("size %d\n", tokens->size);
	// 	printf("-------------------------\n");
	// 	tokens = tokens->next;
	// }
	_token(&tokens);
	tmp = tokens;
	while (tmp)
	{
		tmp = tokens->next;
		for (int k = 0; k < tokens->size; k++)
			free(tokens->str[k]);
		free(tokens->str);
		free(tokens);
		tokens = tmp;
	}
	tokens = NULL;

	return (ret);
}





