#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

typedef struct token
{
	int		type;
	char	*str;
	t_token	*next;
	t_token *prev;
} t_token;

typedef struct command
{
	t_token *tokens;
	int	token_size;
	command *next;
} command;

typedef struct pipelines
{
	t_token	*tokens;
	int		token_size;
	pipelines	*next;
} pipelines;

enum type
{
	T_WORD,
	T_BREAK,
	T_PIPE
} type;

int ft_strlen(char *s);

void	err_fatal();
void	err_execve(char *str);
void	err_cd_arg();
void	err_cd(char *str);

