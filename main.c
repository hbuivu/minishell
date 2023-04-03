#include "tinyshell.h"

void	init_delimiters(t_data *data)
{
	data->delimiters = ":=!";
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_data	data;
	// t_env	*env_ptr;

	init_env(&data, envp);
	init_delimiters(&data);
	//printf only prints (null) if the string has been allocated???
	// print_our_env(data.our_env);
	
	// print_export(&data);
	
	// env_ptr = find_existing_var("something", &data);
	// if (env_ptr == NULL)
	// 	printf("This var doesn't exist\n");
	// else
	// 	printf("This var exists: %s\n", env_ptr->var);

	// int i = is_delimiter('=', &data);
	// printf("%i\n", i);
	
	int i = 0;
	char *str = expand_var("$USER=", &i, &data);
	printf("%s\n", str);
}