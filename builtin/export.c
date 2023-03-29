typedef struct s_list
{
	char *env_var;
	int	p; //for printed
	struct s_list *next;
} t_list;

//find next var to print
//while (p != 0)
	//move to the next on the list
//set print_arg to first node where p == 0
//temp = *our_env
//int comp = ft_strcmp(printarg->env_var, temp->next->env_var)
//if comp < 0 && p == 0
	//print_arg = print_arg->next;
//temp = temp->next
//continue until you reach null (while our_env->next != NULL)
//print var with \n;
//change p in the printed var

void	print_export(t_data *data)
{
	int		i;
	t_list *print_arg;
	
	i = 0;
	while (i < data->num_paths)
	{
		printf("declare -x ");
		//print var with /n
		i++;
	}
	//reset p to 0;
}

void	ft_export(void)
{
	//if just export ->print export
	//if export + var ->add to var
}