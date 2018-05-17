/*
** EPITECH PROJECT, 2017
** joan
** File description:
** kabello
*/

int	my_strlen(char const *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0') {
		i++;
		count++;
	}
	return (count);
}
