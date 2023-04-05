#include "tinyshell.h"

// void	init_delimiters(t_data *data)
// {
// 	data->delimiters = ":=!";
// }

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_data	data;
	// t_env	*env_ptr;

	init_env(&data, envp);
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

	char *str[4] = {"export", "hello", NULL};

	ft_echo(str, &data);

}