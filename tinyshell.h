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

}	t_data;

/************* BUILTINS *************/
/* EXPORT */

/* ECHO */
void	ft_echo(char **str, t_data *data);

/* UTILS */
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