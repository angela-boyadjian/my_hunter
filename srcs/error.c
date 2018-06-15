/*
** EPITECH PROJECT, 2017
** error.c
** File description:
** error handling
*/
#include "my_hunter.h"

int	errors(int ac, char **av, char **envp)
{
	if (ac > 1) {
		if (help(ac, av) == 1)
			return (0);
	}
	if (envp[0] == NULL)
		return (84);
	return (1);
}