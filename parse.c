#include "microshell.h"

int parse(t_token **tokens, char *arg)
{
    int is_break = (strcmp(arg, ";") == 0);
    int is_pipe == (strcmp(arg, "|") == 0);

    if (is_break && !(*tokens))
        return (EXIT_SUCCESS); // 맨 첨에 암것도 없이 break 만 나올때
    if (!is_break && (!(*tokens) || *tokens->type > 1))
        return (ft_lst_addback(tokens, arg)); 
    if (is_break)
        *tokens->type = T_BREAK;
    if (is_pipe)
        *tokens->type = T_PIPE;
    else
        return (add_arg(*tokens, arg));
    return (EXIT_SUCCESS);
}

int ft_lst_addback(t_token **tokens, char *arg)
{
    t_token *new = malloc(sizeof(t_token));
    if (!new)
        err_fatal();
    new->type = T_WORD;
    new->length = 1;
    new->str = NULL;
    new->next= NULL;
    new->prev = NULL;
    if (*tokens == NULL)
        *tokens = new;
    else
    {
        t_token *cur = *tokens;
        while (cur->next)
            cur = cur->next;
        cur->next = new;
        new->prev = cur;
    }
    return (add_arg(*tokens, arg));
}

int add_arg(t_token *tokens, char *arg)
{
    char    **tmp;
    tmp = malloc(sizeof(char *) * (tokens->length + 1));
    if (!tmp)
        err_fatal();
    int i = 0;
    while (i < tokens->length)
        tmp[i] = tokens->str[i++];
    tokens->str = tmp;
    tokens->str[i++] = ft_strdup(arg);
    tokens->str[i] = NULL;
    tokens->length++;
    return (EXIT_SUCCESS);
}