
#include "../tinyshell.h"

char	*lower_str(char *str, t_data *data)
{
	int		i;
	char	*low_str;

	i = 0;
	low_str = (char *)ft_calloc_e(ft_strlen(str) + 1, sizeof(char), data);
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			low_str[i] = str[i] + 32;
		else
			low_str[i] = str[i];
		i++;
	}
	return (low_str);
}

void	execute_builtin(char **arg, t_data *data)
{
	char	*command;

	command = lower_str(arg[0], data);
	if (ft_strncmp(command, "echo", ft_strlen(command)) == 0)
		ft_echo(arg, data);
	else if (ft_strncmp(command, "cd", ft_strlen(command)) == 0)
		ft_cd(arg, data);
	else if (ft_strncmp(command, "pwd", ft_strlen(command)) == 0)
		ft_pwd(data);
	else if (ft_strncmp(command, "export", ft_strlen(command)) == 0)
		ft_export(arg, data);
	else if (ft_strncmp(command, "unset", ft_strlen(command)) == 0)
		ft_unset(arg, data);
	else if (ft_strncmp(command, "env", ft_strlen(command)) == 0)
		ft_env(data);
	// else if (ft_strncmp(command, "exit", ft_strlen(command)) == 0)
	// 	ft_exit(data);
	free(command);
}