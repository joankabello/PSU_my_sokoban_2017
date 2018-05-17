/*
** EPITECH PROJECT, 2017
** joan
** File description:
** kabello
*/

void	my_putchar(char c);

int	my_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
	return (0);
}
