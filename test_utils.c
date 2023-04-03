#include "tinyshell.h"

void	print_splitlist(char **list)
{
	int	i;

	i = 0;
	if (!list)
		printf("(null)");
	while (list[i])
	{
		printf("%s, ", list[i]);
		i++;
	}
	printf("\n");
}

// void	print_our_env(t_env **our_env)
// {
// 	t_env *cur = *our_env;
// 	int	i = -1;;

// 	while (cur)
// 	{
// 		printf("VARIABLE: %s\n", cur->var);
// 		printf("VALUES: ");
// 		if (cur->val == NULL)
// 			printf("(null)");
// 		else
// 			while (cur->val[++i])
// 				printf("%s ", cur->val[i]);
// 		printf("\n");
// 		i = -1;
// 		printf("p: %i\n", cur->p);
// 		cur = cur->next;
// 	}
// }
