#include "microshell.h"

int main(int argc, char **argv, char **envp)
{
    t_token *tokens;

    int i = 1;
    while (argv[i])
        parse(&tokens, argv[i++]);

    
    while (tokens)
    {
        for (int i = 0; i < tokens->size -1; i++)
            printf("%s\n", tokens->str[i]);
        printf("type %d\n", tokens->type);
        printf("token\n");
        tokens = tokens->next;
    }

    return 0;









}





