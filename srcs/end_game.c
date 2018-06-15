/*
** EPITECH PROJECT, 2017
** end_game.c
** File description:
** end game functions
*/
#include "my_hunter.h"

static void	init_hit(struct game *hunter)
{
	hunter->tools.pos.x = 0;
	hunter->tools_2.pos.x = 0;
	hunter->tools_2.pos.y = 200;
	hunter->tools.pos.y = 0;
	hunter->score.hits = 0;
	hunter->score.lives = 3;
}

void	reset_game(struct game *hunter, sfRenderWindow *window, sfEvent event)
{
	if (sfRenderWindow_pollEvent(window, &event)) {
			if (analyse_events(window, event, hunter,
			&(hunter->tools)) == 2) {
				init_hit(hunter);
				my_hunter(hunter, window);
			}
		}
}

void	end_game(sfRenderWindow * window, struct game *hunter, int win)
{
	sfRenderWindow_clear(window, sfBlack);
	hunter->score.text_pos.y = hunter->height / 2;
	hunter->score.text_pos.x = hunter->width / 2 - 120;
	if (win > 0) {
		create_text(hunter, 50, "you win !", 2);
	} else {
		create_text(hunter, 50, "you lose !", 2);
	}
	sfRenderWindow_drawText(window, hunter->score.text, NULL);
	sfRenderWindow_display(window);
}