void	ft_bzero(void *s, unsigned int n)
{
	unsigned char	*string;
	unsigned int	i;

	string = s;
	i = 0;
	while (i < n)
	{
		string[i] = 0;
		i++;
	}
}