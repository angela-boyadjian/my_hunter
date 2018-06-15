/*
** EPITECH PROJECT, 2017
** init_game.c
** File description:
** init game function
*/
#include "my_hunter.h"

void	set_texture(struct game *hunter)
{
	sfSprite_setTexture(hunter->tools.spritesheet,
	hunter->tools.spritesheet_texture, sfTrue);
	sfSprite_setTexture(hunter->tools.background,
	hunter->tools.background_texture, sfTrue);
	sfSprite_setTextureRect(hunter->tools.spritesheet,
	hunter->tools.spritesheet_rect);
}

void	init_game(struct game *hunter)
{
	init_cursor(hunter);
	init_text(hunter);
	init_times(hunter);
	init_images(hunter);
	init_images_2(hunter);
	set_texture(hunter);
	init_noise(hunter);
}