/*
** EPITECH PROJECT, 2017
** joan
** File description:
** kabello
*/

#include	<stdlib.h>
#include	<struct.h>
#include	<unistd.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<errno.h>
#include	<ncurses.h>
#include	<my.h>
#include	<stdio.h>
#include	<curses.h>

void	my_up(WINDOW *window, char **map, position_t p)
{
	if (map[p.r - 1][p.c] != '#') {
		if (map[p.r - 1][p.c] == ' ') {
			map[p.r - 1][p.c] = map[p.r][p.c];
			map[p.r][p.c] = ' ';
			mvwaddch(window, p.r - 1, p.c, map[p.r - 1][p.c]);
			mvwaddch(window, p.r, p.c, map[p.r][p.c]);
		}
		else if (map[p.r - 1][p.c] == 'X' && map[p.r - 2][p.c] != '#') {
			map[p.r - 1][p.c] = 'P';
			map[p.r][p.c] = ' ';
			map[p.r - 2][p.c] = 'X';
			mvwaddch(window, p.r - 1, p.c, map[p.r - 1][p.c]);
			mvwaddch(window, p.r, p.c, map[p.r][p.c]);
			mvwaddch(window, p.r - 2, p.c, map[p.r - 2][p.c]);
		}
	}
}

void	my_down(WINDOW *window, char **map, position_t p)
{
	if (map[p.r + 1][p.c] != '#') {
		if (map[p.r + 1][p.c] == ' ') {
			map[p.r + 1][p.c] = map[p.r][p.c];
			map[p.r][p.c] = ' ';
			mvwaddch(window, p.r + 1, p.c, map[p.r + 1][p.c]);
			mvwaddch(window, p.r, p.c, map[p.r][p.c]);
		}
		else if (map[p.r + 1][p.c] == 'X' && map[p.r + 2][p.c] != '#') {
			map[p.r + 1][p.c] = 'P';
			map[p.r][p.c] = ' ';
			map[p.r + 2][p.c] = 'X';
			mvwaddch(window, p.r + 1, p.c, map[p.r + 1][p.c]);
			mvwaddch(window, p.r, p.c, map[p.r][p.c]);
			mvwaddch(window, p.r + 2, p.c, map[p.r + 2][p.c]);
		}
	}
}

void	my_right(WINDOW *window, char **map, position_t p)
{
	if (map[p.r][p.c + 1] != '#') {
		if (map[p.r][p.c + 1] == ' ') {
			map[p.r][p.c + 1] = map[p.r][p.c];
			map[p.r][p.c] = ' ';
			mvwaddch(window, p.r, p.c + 1, map[p.r][p.c + 1]);
			mvwaddch(window, p.r, p.c, map[p.r][p.c]);
		}
		else if (map[p.r][p.c + 1] == 'X' && map[p.r][p.c + 2] != '#') {
			map[p.r][p.c + 1] = 'P';
			map[p.r][p.c] = ' ';
			map[p.r][p.c + 2] = 'X';
			mvwaddch(window, p.r, p.c + 1, map[p.r][p.c + 1]);
			mvwaddch(window, p.r, p.c, map[p.r][p.c]);
			mvwaddch(window, p.r, p.c + 2, map[p.r][p.c + 2]);
		}
	}
}

void	my_left(WINDOW *window, char **map, position_t p)
{
	if (map[p.r][p.c - 1] != '#') {
		if (map[p.r][p.c - 1] == ' ') {
			map[p.r][p.c - 1] = map[p.r][p.c];
			map[p.r][p.c] = ' ';
			mvwaddch(window, p.r, p.c - 1, map[p.r][p.c - 1]);
			mvwaddch(window, p.r, p.c, map[p.r][p.c]);
		}
		else if (map[p.r][p.c - 1] == 'X' && map[p.r][p.c - 2] != '#') {
			map[p.r][p.c - 1] = 'P';
			map[p.r][p.c] = ' ';
			map[p.r][p.c - 2] = 'X';
			mvwaddch(window, p.r, p.c - 1, map[p.r][p.c - 1]);
			mvwaddch(window, p.r, p.c, map[p.r][p.c]);
			mvwaddch(window, p.r, p.c - 2, map[p.r][p.c - 2]);
		}
	}
}
