/*
** EPITECH PROJECT, 2017
** size.c
** File description:
** handles size
*/
#include "my_hunter.h"

int	get_size(int ac, char **av, struct game *hunter)
{
	hunter->height = 600;
	hunter->width = 800;
	if (ac == 3) {
		hunter->height = my_getnbr(av[1]);
		hunter->width = my_getnbr(av[2]);
	}
	if (hunter->height <= 400 || hunter->width <= 400) {
		my_print_err("Invalid size\n");
		return (84);
	}
	return (0);
}