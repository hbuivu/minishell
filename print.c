#include "tinyshell.h"

void	print_string(int num_str, ...)
{
	int		i;
	t_data	*data;
	va_list	str;
	
	va_start(str, num_str);
	i = 0;
	data = va_arg(str, t_data*);
	while (i < num_str)
	{
		if (printf("%s", va_arg(str, char *)) == -1)
			error(data);
		i++;	
	}
	va_end(str);
}
