/*
** EPITECH PROJECT, 2017
** popup
** File description:
** project
*/

#include	<struct.h>
#include	<unistd.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<errno.h>
#include	<ncurses.h>
#include	<my.h>
#include	<stdio.h>
#include	<curses.h>
#include	<stdlib.h>

struct	position	player(char **map, int Lnumber)
{
	position_t	p;
	int	line;
	int	c;

	line = 0;
	c = 0;
	while (line < Lnumber) {
		c = 0;
		while (map[line][c] != '\0') {
			if (map[line][c] == 'P') {
				p.r = line;
				p.c = c;
			}
			c++;
		}
		line++;
	}
	return (p);
}

int	count_line(char const *filename)
{
	FILE	*file;
	ssize_t	read;
	int	count;
	size_t	len;
	char	*line;

	line = NULL;
	len = 0;
	file = fopen(filename, "r");
	if (file == NULL)
		exit (84);

	while ((read = getline(&line, &len, file)) != -1) {
		count++;
	}
	return (count);
}

void	display_map(char **map, int Lnumber)
{
	WINDOW	*window;
	int	a;
	int	b;

	a = 0;
	b = 0;
	window = get_init();
	while (a != Lnumber) {
		b = 0;
		while (map[a][b] != '\0') {
			mvwaddch(window, a, b, map[a][b]);
			b++;
		}
		a++;
	}
	refresh();
	get_events(a, window, map, Lnumber);
	close_win();
}

void	store_data(char **map, char const *filename, int Lnumber)
{
	FILE	*file;
	ssize_t	read;
	int	a;
	size_t	len;
	char	*line;

	line = NULL;
	len = 0;
	file = fopen(filename, "r");
	a = 0;
	while ((read = getline(&line, &len, file)) != -1) {
		map[a] = my_strdup(line);
		a++;
	}
	display_map(map, Lnumber);
	player(map, Lnumber);
}

int	main(int ac, char **av)
{
	char	*file;
	char	**map;
	int	Lnumber;

	file = av[1];
	if (ac == 1) {
		exit (84);
	}
	if (av[1][0] == '-' && av[1][1] == 'h') {
		write(1, "USAGE\n\t ./my_sokoban map\nDESCRIPTION\n\t", 40);
		write(1, "map  file representing the warehouse map,", 42);
		write(1, " containing '#' for walls,\n\t", 30);
		write(1, "'P' for the player, 'X' for boxes and 'O' ", 42);
		write(1, "for storage locations.\n", 25);
		return (0);
	}
	Lnumber = count_line(file);
	map = malloc(sizeof(*map) * Lnumber);
	store_data(map, file, Lnumber);
	free(map);
	return (0);
}
