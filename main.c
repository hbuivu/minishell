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
		split_var = ft_split(envp[i], '=');
		node->var = ft_strdup(split_var[0]); //check strdup for malloc error
		node->vals = ft_strdup(split_var[1]);
		// print_vals(node);
		node->next = NULL;
		node->prev = cur;
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

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	// t_data	data;
	// t_env	*env_ptr;

	// init_env(&data, envp);
	// init_delimiters(&data);
	//printf only prints (null) if the string has been allocated???
	// print_our_env(data.our_env);
	
	// print_export(&data);
	// char *str = "PATH=i=1:j=2:k=3";
	// char **buf = split_export(str, &data);
	// for (int i = 0; i < 2; i++)
	// 	printf("%s\n", buf[i]);
	
	// env_ptr = find_existing_var("something", &data);
	// if (env_ptr == NULL)
	// 	printf("This var doesn't exist\n");
	// else
	// 	printf("This var exists: %s\n", env_ptr->var);

	// int i = is_delimiter('=', &data);
	// printf("%i\n", i);
	// ft_export("hello=2", &data);
	// print_export(&data);

	// char *str[4] = {"export", "hello", NULL};

	// ft_echo(str, &data);

	char *str = ft_strdup_lim("echo=2", '=');
	printf("%s\n", str);
	free(str);

}