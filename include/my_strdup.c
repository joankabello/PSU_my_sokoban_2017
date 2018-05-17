/*
** EPITECH PROJECT, 2017
** joan
** File description:
** kabello
*/

#include	<stdlib.h>

int	my_strlen(char const *str);

char	*my_strdup(char *str)
{
	char	*dest;
	int	i;
	int	len;

	i = 0;
	len = my_strlen(str);
	dest = malloc(sizeof(len + 1));
	while (str[i] != '\0') {
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
