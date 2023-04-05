#include "../tinyshell.h"

/* print export */
void	print_export(t_data *data)
{
	t_env	*cur;
	t_env	*to_print;

	while (1)
	{
		//find the first key that hasn't been printed
		cur = *(data->env_list);
		while (cur && cur->p == 1)
			cur = cur->next;
		//if everything has been printed, break out of loop
		if (cur == NULL)
			break ;
		//iterate through list to find the next variable to be printed
		to_print = cur;
		cur = cur->next;
		while (cur != NULL)
		{
			if (ft_strncmp(to_print->key, cur->key, ft_strlen(to_print->key) + 1) > 0 && cur->p == 0)
				to_print = cur;
			cur = cur->next;
		}
		//mark p as 1 (printed) and print key
		to_print->p = 1;
		print_string(3, data, "declare -x ", to_print->key, "=");
		if (to_print->val == NULL)
			print_string(1, data, "''\n");
		else
			print_string(2, data, to_print->val, "\n");
	}
	//reset all p to 0;
	cur = *(data->env_list);
	while (cur != NULL)
	{
		cur->p = 0;
		cur = cur->next;
	}
}

/* split variable by only the first '=' and returns an array with key and value */
char	**split_export(char *str, t_data *data)
{
	int		var_len;
	int		val_len;
	char	**ret_split;

	ret_split = (char **)ft_calloc_e(2, sizeof(char *), data);
	var_len = detect_char(str, '=');
	ret_split[0] = (char *)ft_calloc_e(var_len + 1, sizeof(char), data);
	val_len = ft_strlen(str) - (var_len + 1);
	ret_split[1] = (char *)ft_calloc_e(val_len + 1, sizeof(char), data);
	ft_strlcpy(ret_split[0], str, var_len + 1);
	str += (var_len + 1);
	ft_strlcpy(ret_split[1], str, val_len + 1);
	return (ret_split);
}

/* export variables */
void	ft_export(char **arg, t_data *data) 
{	
	t_env	*env_var;
	char	**split_arg;
	int		i;

	i = 1;
	//if only export, print export
	if (!arg[i])
	{
		print_export(data);
		return ;
	}
	while (arg[i])
	{
		//if no '=', add var if it doesn't exist, otherwise do nothing
		if (!detect_char(arg[i], '='))
			if (!find_var_envlist(arg[i], data))
				add_env_var(arg[i], NULL, data);
		//if '=', change value if var exists, otherwise add var and value
		else
		{
			split_arg = split_export(arg[i], data);
			env_var = find_var_envlist(split_arg[0], data);
			if (!env_var)
				add_env_var(split_arg[0], split_arg[1], data);
			else
			{
				env_var->val = ft_strdup_lim(split_arg[1], '\0', data); 
				modify_our_env(env_var, data);
			}
			free_strlist(split_arg);
		}
		i++;	
	}
}




