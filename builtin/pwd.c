#include <tinyshell.h>

void	*ft_pwd(t_data *data)
{
	char	*cwd;

	cwd = get_cwd(NULL, 0);
	if (!cwd)
		error(data);
	print_string(1, data, cwd);
	free(cwd);
}
