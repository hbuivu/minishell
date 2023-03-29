#include "tinyshell.h"

void	init_env(t_data *data, char **envp)
{
	t_env	**our_env;
	t_env	*node;
	t_env	*cur;
	char	**split_var;
	char	**split_val;
	int		i;

	i = -1;
	our_env = (t_env **)ft_calloc(1, sizeof(t_env *));
	while (envp[++i])
	{
		node = (t_env *)ft_calloc(1, sizeof(t_env));
		split_var = ft_split(envp[i], '=');
		split_val = ft_split(split_var[1], ':');
		node->var = ft_strdup(split_var[0]);
		node->val = split_val;
		node->next = NULL;
		free(split_var);
		//we do not free split_val bc we assign it directly to node->val
		if (!*our_env)
			*our_env = node;
		else
			cur->next = node;
		cur = node;
	}
	data->our_env = our_env;
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_data	data;

	init_env(&data, envp);
}