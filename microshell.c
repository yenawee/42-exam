#include "microshell.h"

int _token(t_token **tokens)
{
	while ((*tokens)->prev)
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
	if (tokens)
		_token(&tokens);
	int ret  = execute(tokens);
	//while (tokens)
	//{
	//	for (int i = 0; i < tokens->size - 1; i++)
	//		printf("%s\n", tokens->str[i]);
	//	printf("type %d\n", tokens->type);
	//	printf("-------------------------\n");
	//	tokens = tokens->next;
	//}

	return (ret);









}





