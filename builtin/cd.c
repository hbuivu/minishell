#include "tinyshell.h"

void	ft_cd(char **cmd, t_data *data)
{
	//change directory
	//check env pwd 
	//put that into another buffer
	//change env pwd to current directory
	//check if oldpwd exists
		//if yes, go to old_pwd
		//change to what is in the buffer
		//if no, create an old_pwd node
	//change array of env based on linked list changes
	//change directory display??????

	char	*curr_dir;
	char	*old_dir;
	t_env	*pwd_var;
	t_env 	*old_pwd_var;
	//changed directories
	if (chdir(cmd[1]) != 0)
		error(data);
	//copy over previous directory
	pwd_var = find_existing_var("PWD", data);
	old_dir = ft_strdup(pwd_var->vals); //malloc error later
	//find oldpwd if it exists
	old_pwd_var = find_existing_var("OLDPWD", data);
	if (old_pwd_var == NULL)
		add_env_var("OLDPWD", old_dir, data);
	else
	{
		free(old_pwd_var->vals);
		old_pwd_var->vals = ft_strdup(old_dir);
	}
	//change our_env array
	modify_our_env(data);
	//change current pwd
	curr_dir = get_cwd(NULL, 0);
	pwd_var->vals = curr_dir;
	
}