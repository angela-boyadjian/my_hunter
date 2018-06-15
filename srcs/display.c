/*
** EPITECH PROJECT, 2017
** sprites_display.c
** File description:
** functions to display sprites
*/
#include "my_hunter.h"

void	text_score(struct game *hunter,
	sfRenderWindow *window, int hits)
{
	hunter->score.text_pos.x = 10;
	hunter->score.text_pos.y = 10;
	create_text(hunter, 30, "score: ", 1);
	sfRenderWindow_drawText(window, hunter->score.text, NULL);
	hunter->score.text_pos.x = 120;
	hunter->score.text_pos.y = 10;
	create_text(hunter, 30, my_itoa(hits), 1);
	sfRenderWindow_drawText(window, hunter->score.text, NULL);
}

void	text_lives(struct game *hunter,
	sfRenderWindow *window, int lives)
{
	hunter->score.text_pos.x = hunter->width - 150;
	hunter->score.text_pos.y = 10;
	create_text(hunter, 30, "lives: ", 3);
	sfRenderWindow_drawText(window, hunter->score.text, NULL);
	hunter->score.text_pos.x = hunter->width - 50;
	hunter->score.text_pos.y = 10;
	create_text(hunter, 30, my_itoa(lives), 3);
	sfRenderWindow_drawText(window, hunter->score.text, NULL);
}

void	display_sprite(sfRenderWindow *window, struct images *tools,
	int x, int y)
{
	sfSprite_setPosition(tools->spritesheet, tools->pos);
	move_rect(&(tools->spritesheet_rect), x, y);
	sfSprite_setTextureRect(tools->spritesheet,
	tools->spritesheet_rect);
	sfRenderWindow_drawSprite(window, tools->spritesheet, NULL);
}

static void display_target(sfRenderWindow *window, struct target *cursor)
{
	sfSprite_setPosition(cursor->target, cursor->target_pos);
	sfRenderWindow_drawSprite(window, cursor->target, NULL);
}

void	handle_sprites(struct game *hunter, sfRenderWindow *window)
{
	sfRenderWindow_drawSprite(window, hunter->tools.background, NULL);
	display_sprite(window, &(hunter->tools), 110, 330);
	display_sprite(window, &(hunter->tools_2), 80, 640);
	display_target(window, &(hunter->cursor));
}