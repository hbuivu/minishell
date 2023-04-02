//printf returns a negative value if there's an error 
#include "../tinyshell.h"

void	print_values(t_val **list, t_data *data)
{
	t_val *cur;

	cur = *list;
	while (cur)
	{
		if (cur->next && printf("%s:", cur->val) == -1)
			error(data);
		else if (!cur->next && printf("%s\n", cur->val) == -1)
			error(data);
		cur = cur->next;
	}
}
void	print_export(t_data *data)
{
	t_env	*temp;
	t_env	*to_print;

	while (1)
	{
		//find the first var that hasn't been printed
		temp = *(data->our_env);
		while (temp && temp->p == 1)
			temp = temp->next;
		//if everything has been printed, break out of loop
		if (temp == NULL)
			break ;
		//iterate through list to find the next variable to be printed
		to_print = temp;
		temp = temp->next;
		while (temp != NULL)
		{
			if (ft_strncmp(to_print->var, temp->var, ft_strlen(to_print->var) + 1) > 0 && temp->p == 0)
				to_print = temp;
			temp = temp->next;
		}
		//mark p as 1 (printed) and print var
		to_print->p = 1;
		print_string(3, data, "declare -x ", to_print->var, "=");
		if (to_print->vals == NULL)
			print_string(1, data, "''\n");
		else
			print_values(to_print->vals, data);
	}
	//reset all p to 0;
	temp = *(data->our_env);
	while (temp != NULL)
	{
		temp->p = 0;
		temp = temp->next;
	}
}

//find if a variable exists and return the pointer to the variable if it exists. If not return NULL
t_env	*find_existing_var(char *var, t_data *data)
{
	t_env *env_var;

	env_var = *(data->our_env);
	while (env_var)
	{
		if (ft_strncmp(env_var->var, var, ft_strlen(var) + 1) == 0)
			return (env_var);
		env_var = env_var->next;
	}
	return (NULL);
}
// //vals are a linked list of strings
// //check values by $ and expand all
// //create final temp_vals
// //split final temp_vals by :
// //while there are existing vals, check the new vals and against existing vals and change if necessary
// //if there are still new vals, add nodes
// //make a list of special characters that can't be used as delimiters

//checks to see if a character is a delimiter. returns 0 if not, 1 if yes
int	is_delimiter(char c, t_data *data)
{
	int	i;

	i = 0;
	while (data->delimiters[i])
	{
		if (c == data->delimiters[i])
			return (1);
		i++;
	}
	return (0);
}

//expands a variable to values if the variable exists
char	*expand_var(char *val, int *i, t_data *data)
{
	int		len;
	int		counter;
	char	*var_name;
	t_env	*exist_var;
	char	*var_values;
	char	*temp;

	(*i)++;
	counter = *i;
	len = 0;
	var_values = NULL;
	while (!is_delimiter(val[counter], data))
	{
		counter++;
		len++;
	}
	printf("%i\n", len);
	var_name = (char *)ft_calloc(len + 1, sizeof(char));
	if (!var_name)
		error(data);
	while (!is_delimiter(val[*i], data))
	{
		var_name[*i] = val[*i];
		(*i)++;
	}
	printf("%s\n", var_name);
	exist_var = find_existing_var(var_name, data);
	free(var_name);
	if (exist_var)
	{
		var_values = ft_strdup((*exist_var->vals)->val);
		(*exist_var->vals) = (*exist_var->vals)->next;
		while((*exist_var->vals)->val)
		{
			temp = ft_strjoin(var_values, (*exist_var->vals)->val);
			free(var_values);
			var_values = temp;
			(*exist_var->vals) = (*exist_var->vals)->next;
		}
	}
	return (var_values);
}

// //expand the whole string of values to the final value string
// char	**expand_val(char *val, t_data *data)
// {
// 	//copy val up until but not including $
// 	//scan $ up until delimiter detected(whatever that is)
// 	//skipping the dollar sign, compare that variable against existing env variables
// 	//if the variable exists
// 		//while values, ft_strjoin values to existing val_str
// 	//continue to copy the value up until the next $
// 	//repeat
// 	char	*final_val;
// 	char	*var_values;
// 	char	*temp;
// 	char	**return_vals;
// 	int		i;
// 	int		j;

// 	final_val = (char *)ft_calloc(ft_strlen(val), sizeof(char));
// 	if (!final_val)
// 		error(data);
// 	while(val[i])
// 	{
// 		if (val[i] != '$')
// 		{
// 			final_val[i] = val[i];
// 			i++;
// 			j++;
// 		}
// 		else
// 		{
// 			var_values = expand_var(val, &i, data);
// 			temp = ft_strjoin(final_val, var_values);
// 			free(final_val);
// 			final_val = temp;
// 		}
// 	}
// 	return_vals = ft_split(final_val, ':');
// 	if (!return_vals)
// 	{
// 		free(final_val);
// 		error(data);
// 	}
// 	free(final_val);
// 	return (return_vals);
// }

// //add value to an already created env_var
// void	parse_values(t_env *env_var, char *val, t_data *data) 
// {
// 	char	**split_val;
// 	t_val	*exist_val;
// 	t_val	*node;
// 	int		i;


// 	i = 0;
// 	exist_val = *(env_var->vals);
// 	if (ft_strchr(val, '$'))
// 		split_val = expand_val(val, data);
// 	else
// 	{
// 		split_val = ft_split(val, ':');
// 		if (!split_val)
// 			error(data);
// 	}
// 	while(exist_val)
// 	{
// 		if (ft_strncmp(exist_val->val, split_val[i], ft_strlen(split_val[i]) + 1) != 0)
// 		{
// 			free(exist_val->val);
// 			exist_val->val = ft_strdup(split_val[i]);
// 			if (!exist_val->val)
// 				error(data);
// 		}
// 		i++:
// 		if (exist_val->next == NULL)
// 			break ;
// 		exist_val = exist_val->next;
// 	}
// 	while (split_val[i])
// 	{
// 		node = (t_val *)ft_calloc(1, sizeof(t_val));
// 		if (!node)
// 			error(data);
// 		node->val = ft_strdup(split_val[i]);
// 		if (!node->val)
// 			error(data);
// 		node->next = NULL;
// 		exist_val->next = node;
// 		i++;
// 		exist_val = exist_val->next;
// 	}
// 	free_strlist(temp_vals);
// }

// void	add_var(char *var, char *val, t_data *data)
// {
// 	//ft_calloc new t_env;
// 	//var = var
// 	//parse_values for this node
// 	//add to the front of the linked list of env variables
// 	t_env	*new_var;

// 	new_var = (t_env *)ft_calloc(1, sizeof(t_env));
// 	if (!new_var)
// 		error(data);
// 	new_var->var = ft_strdup(var);
// 	new_var->val = parse_values(new_var, val, data); 
// 	//add node to the end of env variables
// }

// void	ft_export(t_data *data)
// {
// 	//NOTE: DOES NOT ACCOUNT FOR SPECIAL CHARACTERS
// 	int		i;
// 	char	*split_var;
// 	t_env	*env_var;

// 	i = 1;
// 	if (data->command[i] == NULL)
// 	{
// 		print_export(data);
// 		return ;
// 	}
// 	while (data->command[i])
// 	{
// 		//check command for =
// 		//if no =
// 			//check for existing variable
// 			//if none, add the variable (node)
// 		//if yes =
// 			//split the variable
// 			//check for existing variable
// 				//if existing variable
// 					//change the value if needed
// 				//if not existing variable
// 					//add the variable and value (node)
// 			//free split_variable
// 			//NOTE: this doesnt take into account if the multiple values also have = in them
// 		// find_existing_var should return location of the path
		
// 		if (ft_strchr(data->command[i], '=') == NULL)
// 		{
// 			env_var = find_existing_var(data->command[i], data);
// 			if (!env_var)
// 				add_var(data->command[i], NULL, data);
// 		}		
// 		else
// 		{
// 			split_var = ft_split(data->command[i], '=');
// 			env_var = find_existing_var(split_var[0], data);
// 			if (env_var)
// 				parse_values(env_var, split_var[1], data);
// 			else
// 				add_var(split_var[0], split_var[1], data);
// 			free_strlist(split_var);
// 		}
// 		i++;

// 	}
// }

