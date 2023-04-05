#include "tinyshell.h"

void	print_strlist(char **list)
{
	int	i;

	i = 0;
	if (!list)
		printf("(null)");
	while (list[i])
	{
		printf("%s, ", list[i]);
		i++;
	}
	printf("\n");
}

void	print_env_list(t_env **env_list)
{
	t_env *cur;

	cur = *env_list;
	while (cur)
	{
		printf("%s", cur->key);
		printf("=");
		if (cur->val)
			printf("%s\n", cur->val);
		else
			printf("(null)\n");
		cur = cur->next;
	}
}

void	print_data(t_data *data)
{
	printf("*****COMMANDS*****\n");
	if (data->cmd)
		print_strlist(data->cmd->array_arg);
	printf("*****ENV LIST*****\n");
	if (data->env_list)
		print_env_list(data->env_list);
	printf("*****OUR ENV*****\n");
	if (data->our_env)
		print_strlist(data->our_env);
}


