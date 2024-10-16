#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

char	*ft_trim(char *path)
{
	int		i;
	char	*aux;

	i = 6;
	while (path[i] != ':' && path[i] != '\0')
		i ++;
	if (i > 3)
		aux = malloc(sizeof(char) * (i - 3));
	else
		aux = malloc(sizeof(char) * 2);
	if (i > 3)
		i -= 4;
	else
		i = 7;
	aux[i] = '\0';
		i ++;
	while (i != 6)
	{
		aux[i - 6] = path[i];
		i --;
	}
	return (aux);
}

int main(int nargs, char **args, char **env)
{
	char    *raw_path;
	char    *path;

	raw_path = getenv("PATH");
	path = ft_trim(raw_path);
	printf("Path: %s", path);
}
