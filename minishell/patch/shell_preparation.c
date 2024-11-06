#include "../include/minishell.h"

int			ft_count_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		i ++;
		envp ++;
	}
	return (i);
}

int	ft_prep_env(char **envp, t_shell *minishell) 
{
	int		i;
	t_env	*aux;
	char	*name;

	i = 1;
	name = ft_get_env(*envp);
	if (name == NULL)
		return (-1);
	minishell->env[0] = ft_plstnew(name, getenv(name));
	if (minishell->env[0] == NULL)
		return (ft_plstclear(minishell->env));
	while (envp[i] != NULL)
	{
		name = ft_get_env(envp[i]);
		if (name == NULL)
			return (-1);
		aux = ft_plstnew(name, getenv(name));
		if (aux == NULL)
			return (ft_plstclear(minishell->env));
		ft_plstadd_back(minishell->env, aux);
		i ++;
	}
	return (0);
}

char	*ft_get_env(char *str)
{
	int	i;
	char	*toreturn;

	i = ft_strlen(str) - ft_strlen(ft_strchr(str, '=') - 1);
	if (i == -1)
		return (NULL);
	toreturn = malloc(i * sizeof(char));
	if (toreturn == NULL)
		return (NULL);
	toreturn[i] = '\0';
	while (i != -1)
	{
		toreturn[i] = str[i];
		i --;
	}
	return (toreturn);
}

t_shell		*ft_prepare_values(char **envp)
{
	t_shell		*minishell;

	minishell = malloc(sizeof(t_shell));
	if (minishell == NULL)
		return (NULL);
	minishell->env = malloc(sizeof(t_env *) * ft_count_env(envp));
	if (ft_prep_env(envp, minishell) == -1)
		return (ft_mass_free(minishell, NULL, NULL, NULL));
	return (minishell);
}