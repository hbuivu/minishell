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

// typedef struct s_val
// {
// 	char 			*val;
// 	struct s_val	*next;
// }	t_val;

// typedef struct	s_env
// {
// 	char			*var;
// 	t_val			**vals;
// 	int				p; //for printed
// 	struct s_env	*next;
// }	t_env;

typedef struct	s_env
{
	char			*var;
	char			*vals;
	int				p; //for printed
	struct s_env	*next;
}	t_env;

typedef struct s_data
{
	t_cmd	*cmd;
	t_env	**env_list;
	char	**our_env;
	// char	*delimiters;
}	t_data;

/* TESTERS */
void	print_our_env(t_env **our_env);
void	print_splitlist(char **list);

/* BUILTINS */
void	print_export(t_data *data);
char	**split_export(char *str, t_data *data);

/* EXPORT */
t_env	*find_existing_var(char *var, t_data *data);
int		is_delimiter(char c, t_data *data);
char	*expand_var(char *val, int *i, t_data *data);
void	ft_export(char *arg, t_data *data);

/* STRUCTURES */
void	init_env(t_data *data, char **envp);

/* UTILS */
void	print_string(int num_str, ...);
void	error(t_data *data);

#endif