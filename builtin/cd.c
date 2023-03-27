void	ft_cd(char **cmd)
{
	char *curr_dir;

	if (chdir(cmd[1]) != 0)
		//error -> bash: cd: path: No such file or directory
	curr_dir = get_cwd();
	rl_on_new_line();
	rl_replace_line(curr_dir, 0);
	rl_redisplay();
	
}