/*
** EPITECH PROJECT, 2017
** joan
** File description:
** joan
*/

#include	"struct.h"

#ifndef	MY_H_
#define	MY_H_

struct	position	player(char **map, int Lnumber);

void	my_left(WINDOW *window, char **map, position_t p);

void	my_right(WINDOW *window, char **map, position_t p);

void	my_down(WINDOW *window, char **map, position_t p);

void	my_up(WINDOW *window, char **map, position_t p);

void	get_events(int a, WINDOW *window, char **map, int Lnumber);

char	*my_strdup(char *str);

int	my_put_nbr(int nb);

int	my_putstr(char *str);

void	my_putchar(char c);

int	my_strlen(char const *str);

WINDOW	*get_init(void);

void	close_win(void);

#endif
