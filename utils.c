#include "microshell.h"

int ft_strlen(char *s)
{
	int i = 0;
	if (!s)
		return 0;
	while (s[i])
		i++;
	return (i);
}


char    *ft_strdup(char *s)
{
	char    *ret;
	int     len = ft_strlen(s);

	ret = malloc(len + 1);
	if (!ret)
		return NULL;
	int i = 0;
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
