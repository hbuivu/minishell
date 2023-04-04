#include "tinyshell.h"

// /*for t_val*/
// t_val	**create_t_val(char **val, t_data *data)
// {
// 	t_val	**val_list;
// 	t_val	*cur;
// 	t_val	*node;
// 	int		i;

// 	val_list = (t_val **)ft_calloc(1, sizeof(t_val *));
// 	if (!val_list)
// 		error(data);
// 	i = 0;
// 	*val_list = NULL;
// 	while (val[i])
// 	{
// 		node = (t_val *)ft_calloc(1, sizeof(t_val));
// 		if (!node)
// 			error(data);
// 		node->val = ft_strdup(val[i]);
// 		if (!node->val)
// 			error(data);
// 		node->next = NULL;
// 		if (!*val_list)
// 			*val_list = node;
// 		else
// 			cur->next = node;
// 		cur = node;
// 		i++;
// 	}
// 	return (val_list);
// }

// void	print_vals(t_env *node)
// {
// 	if (!node->vals)
// 	{
// 		printf("NULL\n");
// 		return ;
// 	}
// 	t_val *v = *(node->vals);
// 	printf("%s\n", v->val);
// }

// void	init_env(t_data *data, char **envp)
// {
// 	t_env	**env_list;
// 	t_env	*node;
// 	t_env	*cur;
// 	char	**split_var;
// 	char	**split_val;
// 	int		i;

// 	i = -1;
// 	env_list = (t_env **)ft_calloc(1, sizeof(t_env *));
// 	while (envp[++i])
// 	{
// 		node = (t_env *)ft_calloc(1, sizeof(t_env));
// 		split_var = ft_split(envp[i], '=');
// 		split_val = ft_split(split_var[1], ':');
// 		node->var = ft_strdup(split_var[0]);
// 		if (!split_val)
// 			node->vals = NULL;
// 		else
// 			node->vals = create_t_val(split_val, data);
// 		// print_vals(node);
// 		node->next = NULL;
// 		// free(split_var);
// 		// free(split_val);
// 		//we do not free split_val bc we assign it directly to node->val
// 		if (!*env_list)
// 			*env_list = node;
// 		else
// 			cur->next = node;
// 		cur = node;
// 	}
// 	data->env_list = env_list;
// }

void	init_env(t_data *data, char **envp)
{
	t_env	**env_list;
	t_env	*node;
	t_env	*cur;
	char	**split_var;
	int		i;

	i = -1;
	env_list = (t_env **)ft_calloc(1, sizeof(t_env *));
	while (envp[++i])
	{
		node = (t_env *)ft_calloc(1, sizeof(t_env));
		split_var = ft_split(envp[i], '=');
		node->var = ft_strdup(split_var[0]); //check strdup for malloc error
		node->vals = ft_strdup(split_var[1]);
		// print_vals(node);
		node->next = NULL;
		// free(split_var);
		// free(split_val);
		//we do not free split_val bc we assign it directly to node->val
		if (!*env_list)
			*env_list = node;
		else
			cur->next = node;
		cur = node;
	}
	data->env_list = env_list;
}