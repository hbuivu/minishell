#ifndef TINYSHELL_H
# define TINYSHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_cmd
{
	char	**array_arg;
}	t_cmd;

typedef struct	s_env
{
	char			*var;
	char			**val;
	int				p; //for printed
	struct s_env	*next;
}	t_env;

typedef struct s_data
{
	t_cmd	*cmd;
	t_env	**our_env; 
}	t_data;

#endif