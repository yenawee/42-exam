#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

typedef struct token
{
	int		type; //pipe 인지, break 인지
	char	**str;
	int		size;
	int		fd[2];
	struct token	*next;
	struct token	*prev;
} t_token;


enum type
{
	T_WORD = 1,
	T_PIPE,
	T_BREAK
} type;

int		ft_strlen(char *s);
char	*ft_strdup(char *s);

void	err_fatal();
void	err_execve(char *str);
void	err_cd_arg();
void	err_cd(char *str);

int parse(t_token **tokens, char *arg);
int	excute(t_token *tokens, char **envp);



