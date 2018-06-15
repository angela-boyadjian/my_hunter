/*
** EPITECH PROJECT, 2017
** create_text.c
** File description:
** functions for text
*/
#include "my_hunter.h"

static void	set_color(struct game *hunter, int color)
{
	if (color == 1)
		sfText_setColor(hunter->score.text, sfRed);
	else if (color == 2)
		sfText_setColor(hunter->score.text, sfBlue);
	else
		sfText_setColor(hunter->score.text, sfBlack);
}

void	handle_text(struct game *hunter, sfRenderWindow *window,
	int hits, int lives)
{
	text_score(hunter, window, hits);
	text_lives(hunter, window, lives);
}

void	init_text(struct game *hunter)
{
	hunter->score.lives = 3;
	hunter->score.hits = 0;
	hunter->score.font = sfFont_createFromFile("utils/font.ttf");
	hunter->score.text = sfText_create();
}

void	create_text(struct game *hunter, int size, char *str, int color)
{
	sfText_setFont(hunter->score.text, hunter->score.font);
	sfText_setString(hunter->score.text, str);
	sfText_setCharacterSize(hunter->score.text, size);
	set_color(hunter, color);
	sfText_setPosition(hunter->score.text, hunter->score.text_pos);
}