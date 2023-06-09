#include "tinyshell.h"

void	init_env(t_data *data, char **envp)
{
	t_env	**env_list;
	t_env	*node;
	t_env	*cur;
	char	**split_var;
	int		i;

	i = -1;
	env_list = (t_env **)ft_calloc(1, sizeof(t_env *));
	cur = NULL;
	while (envp[++i])
	{
		node = (t_env *)ft_calloc(1, sizeof(t_env));
		split_var = split_env_var(envp[i], data);
		node->key = ft_strdup_lim(split_var[0], '\0', data);
		node->val = ft_strdup_lim(split_var[1], '\0', data);
		node->next = NULL;
		node->prev = cur;
		free_strlist(split_var);
		if (!*env_list)
			*env_list = node;
		else
			cur->next = node;
		cur = node;
	}
	data->env_list = env_list;
}

void	init_test_data(t_data *data, char **envp)
{
	data->cmd = NULL;
	data->env_list = NULL;
	data->our_env = NULL;
	init_env(data, envp);
	modify_our_env(NULL, data);
	data->home_dir = getenv("HOME");
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	// (void)envp;
	t_data	data;
	
	init_test_data(&data, envp);
	// print_data(&data);
}