/*
** EPITECH PROJECT, 2017
** move.c
** File description:
** move functions
*/
#include "my_hunter.h"

void move_rect(sfIntRect *spritesheet_rect, int offset, int max_value)
{
	if (spritesheet_rect->left >= max_value - offset) {
		spritesheet_rect->left = 0;
	} else {
		spritesheet_rect->left += offset;
	}
}

int	set_pos(struct images *tools, sfRenderWindow *window,
	sfEvent event, struct game *hunter)
{
	static int	count = 100;

	if (analyse_events(window, event, hunter, tools) == 1) {
		tools->pos.x = tools->init_pos.x;
		tools->pos.y = tools->init_pos.y;
		return (1);
	} else if (analyse_events(window, event, hunter, tools) == -1) {
		return (-1);
	}
	if (tools->pos.x > hunter->width + 50) {
		tools->pos.x = -5;
		tools->pos.y = count;
		count+= 100;
	}
	if (count >= hunter->height)
		count = 100;
	return (0);
}