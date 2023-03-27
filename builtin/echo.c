
//or change arg to char *str if possible
void	ft_echo(char **str)
{
	int	i;
	int	nl;

	if (ft_strncmp(str[1], "-n", 3) == 0) //if there is -n flag, so no newline after the line
	{
		i = 2;
		nl = 0;
	}
	else //add a newline after printing line
	{
		i = 1;
		nl = 1;
	}
	while (str[i])
	{
		if (str[i + 1] != NULL)
			printf("%s ", str[i]);
		else if (str[i + 1] == NULL)
		{
			printf("%s", str[i]);
			if (nl == 1)
				printf("\n");
		}
		i++;
	}
}
