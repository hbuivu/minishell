#ifndef TINYSHELL_H
# define TINYSHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_cmd
{
	char	**array_arg;
}	t_cmd;

typedef struct	s_env
{
	char			*key;
	char			*val;
	int				p; //for printed
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

typedef struct s_data
{
	t_cmd	*cmd;
	t_env	**env_list;
	char	**our_env;
	char	*home_dir;

}	t_data;

/************* BUILTINS *************/
void	ft_cd(char **arg, t_data *data);
void	ft_echo(char **str, t_data *data);
void	ft_env(t_data *data);
void	ft_export(char **arg, t_data *data);
void	*ft_pwd(t_data *data);
void	ft_unset(char **arg, t_data *data);

/* BUILTIN */
void	execute_builtin(char **arg, t_data *data);

/* ENV VAR */
t_env	*find_var_envlist(char *key, t_data *data);
void	modify_our_env(t_env *env_var, t_data *data);
void	add_env_var(char *key, char *val, t_data *data);

/* UTILS */
int		detect_char(char *str, char c);
void	print_string(int num_str, ...);
void	error(t_data *data);
void	print_string(int num_str, ...);
void	*ft_calloc_e(size_t count, size_t size, t_data *data);
char	*ft_strdup_lim(const char *s1, char c, t_data *data);
void	free_strlist(char **str);


/* TESTERS */
void	print_strlist(char **list);
void	print_data(t_data *data);

#endif