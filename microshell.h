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
	struct token	*next;
	struct token	*prev;
} t_token;

typedef struct command
{
	t_token *tokens;
	int	token_size;
	struct command	*next;
} t_command;

typedef struct pipelines
{
	t_token	*tokens;
	int		token_size;
	t_command *commands;
	struct	pipelines	*next;
} t_pipelines;

enum type
{
	T_WORD = 1,
	T_BREAK,
	T_PIPE
} type;

int		ft_strlen(char *s);
char	*ft_strdup(char *s);

void	err_fatal();
void	err_execve(char *str);
void	err_cd_arg();
void	err_cd(char *str);



