/*
** EPITECH PROJECT, 2017
** joan
** File description:
** kabello
*/

#include	<struct.h>
#include	<unistd.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<ncurses.h>
#include	<my.h>
#include	<stdio.h>
#include	<curses.h>
#include	<stdlib.h>

void	get_events(int a, WINDOW *window, char **map, int Lnumber)
{
	position_t	p;

	while (42) {
		a = getch();
		if (a == 65) {
			p = player(map, Lnumber);
			my_up(window, map, p);
		}
		else if (a == 66) {
			p = player(map, Lnumber);
			my_down(window, map, p);
		}
		if (a == 67) {
			p = player(map, Lnumber);
			my_right(window, map, p);
		}
		else if (a == 68) {
			p = player(map, Lnumber);
			my_left(window, map, p);
		}
	}
}

WINDOW	*get_init(void)
{
	WINDOW  *window;

	window = initscr();
	noecho();
	curs_set(0);
	return (window);
}

void	close_win(void)
{
	endwin();
}
