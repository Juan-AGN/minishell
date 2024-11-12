#include "../../include/minishell.h"

char	*ft_handlesingles(char *str)
{
	int	i;

	while (str[i] != 39 && str[i] != '\0')
		i ++;
	return (ft_strndup(str, i - 1));
}