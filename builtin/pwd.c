#include <limits.h>

char	*get_cwd(void)
{
	char	*cwd;

	cwd = (char *)ft_calloc(PATH_MAX, sizeof(char));
	if (!cwd)
		//return a malloc error and exit program
	getcwd(cwd, PATH_MAX);
		//errno is set so maybe we can use errno?? finally?
		//otherwise just return NULL and take care of the error in the next function
	return (cwd);
}

void	*ft_pwd(void)
{
	char *cwd = get_cwd();
	if (cwd == NULL)
		//return an error on function and exit;
	printf("%s\n", cwd);
}
