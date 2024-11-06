#include "../include/minishell.h"

int	ft_search_space(char *str)
{
	while (*str)
	{
		if (*str <= 32)
			str ++;
		else
			return (0);
	}
	return (1);
}

int main(int argc, char **argv, char **envp)
{
	char	*input;
	char	*cwd = NULL;
	t_shell	*minishell;

/* hay que tener en cuenta que tendriamos que imprimir tambien el nombre de
usuario y de la maquina como lo hace la prompt original para eso hay que
coger variables del PATH y otras cosas, ademas hay que ver cuando se imprime
el $ y cuando el # cuando este en modo administrador, esto es solo una aprox*/

//printf("%s@minishell42:%s~$ ", getenv("USER"), cwd);

/*FOR CHECKING ENVS: 		printf("\n %i ENV ORIGINAL | %s |", argc, envp[argc]);
*/
	minishell = ft_prepare_values(envp);
	rl_redisplay();
	argc = 0;
	argv = NULL;
	while (1)
	{
		cwd = getcwd(NULL, 0); //determina sola la memoria
		if (cwd != NULL)
			input = readline(cwd);
		else
		{
			free(cwd);
			perror("getcwd() error");
			return 1;
		}
		if (ft_strncmp(input, "exit\0", 5) == 0)
		{
			free(input);
			free(cwd);
			rl_clear_history();
			break;
		}
		if (ft_search_space(input) == 0)
			add_history(input);
		else
			printf("");
		printf("%s\n", ft_plstsearch(minishell->env[0], input));
		free(input);
		free(cwd);
	}
	rl_clear_history();
	return 0;
}