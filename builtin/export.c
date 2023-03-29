//printf returns a negative value if there's an error 
#include "tinyshell.h"

void	print_export(t_data *data)
{
	t_list	*temp;
	t_list	*to_print;

	while (1)
	{
		//find the first var that hasn't been printed
		temp = *(data->our_env);
		while (temp->p == 1)
			temp = temp->next;
		//if everything has been printed, break out of loop
		if (temp == NULL)
			break ;
		//iterate through list to find the next variable to be printed
		to_print = temp;
		temp = temp->next;
		while (temp != NULL)
		{
			if (ft_strcmp(to_print->var, temp->var) < 0 && temp->p == 0)
				to_print = temp;
			temp = temp->next;
		}
		//mark p as 1 (printed) and print var
		to_print->p = 1;
		if (printf("declare -x ") < 0)
			//error
		if (printf("%s=", to_print->var) < 0)
			//error
		if (to_print->val == NULL && printf("''") < 0)
			//error
		else if (to_print->val != NULL && printf("%s\n", to_print->val) < 0)
			//error
	}
	//reset all p to 0;
	temp = *(data->our_env);
	while (temp != NULL)
	{
		temp->p = 0;
		temp = temp->next;
	}
}

void	ft_export(t_data *data)
{
	//NOTE: DOES NOT ACCOUNT FOR SPECIAL CHARACTERS
	int		i;
	char	*split_line;
	t_list	*temp;

	i = 1
	if (data->command[i] == NULL)
	{
		print_export(data);
		return ;
	}
	while (data->command[i])
	{
		//check command for = sign
		split_line = ft_split(command[i], '=');
		//check if the variable already exists
		temp = *(data->our_env);
		while (temp)
		{
			if (ft_strcmp(split_line[0], temp->var) == 0)
			{
				if (/*check command for = sign*/)
					temp->val = split_line[1];
				break;
			}
			temp = temp->next;
		}
		if (temp == NULL)
			//create node to add to our_env
			//node->var = split_line[0];
			//node->val = split_line[1];
			//attache node to end of our_env
		free(split_line); //use free_splitline function
		i++;
	}
}