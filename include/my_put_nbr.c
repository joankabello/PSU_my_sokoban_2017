/*
** EPITECH PROJECT, 2017
** joan
** File description:
** kabello
*/

void	my_putchar(char c);

int	my_put_nbr(int nb)
{
	int	i;

	i = 0;
	if (nb < 0) {
		my_putchar('-');
		nb = nb * (-1);
	}

	if (nb >= 0) {
		if (nb >= 10) {
			i = (nb % 10);
			nb = (nb - i) / 10;
			my_put_nbr(nb);
			my_putchar(48 + i);
		}
		else
			my_putchar(48 + nb % 10);
	}
	return (0);
}
