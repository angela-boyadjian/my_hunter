/*
** EPITECH PROJECT, 2017
** init_functions.c
** File description:
** init functions file
*/
#include "my_hunter.h"

void	init_times(struct game *hunter)
{
	hunter->gear.clock = sfClock_create();
	hunter->gear.seconds = 0.0;
}

void	init_images_2(struct game *hunter)
{
	hunter->tools_2.spritesheet_texture =
	hunter->tools.spritesheet_texture;
	hunter->tools_2.spritesheet = hunter->tools.spritesheet;
	hunter->tools_2.spritesheet_rect.top = 110;
	hunter->tools_2.spritesheet_rect.left = 110;
	hunter->tools_2.spritesheet_rect.width = 80;
	hunter->tools_2.spritesheet_rect.height = 80;
	hunter->tools_2.pos.x = 0;
	hunter->tools_2.init_pos.x = 0;
	hunter->tools_2.init_pos.y = 200;
	hunter->tools_2.pos.y = 200;
}

void	init_images(struct game *hunter)
{
	hunter->tools.spritesheet_texture =
	sfTexture_createFromFile("utils/birds.png", NULL);
	hunter->tools.background_texture =
	sfTexture_createFromFile("utils/background.png", NULL);
	hunter->tools.spritesheet = sfSprite_create();
	hunter->tools.background = sfSprite_create();
	hunter->tools.spritesheet_rect.top = 0;
	hunter->tools.spritesheet_rect.left = 0;
	hunter->tools.spritesheet_rect.width = 110;
	hunter->tools.spritesheet_rect.height = 110;
	hunter->tools.pos.x = 0;
	hunter->tools.init_pos.x = 0;
	hunter->tools.init_pos.y = 0;
	hunter->tools.pos.y = 0;
}

void	init_noise(struct game *hunter)
{
	hunter->noise.buffer = sfSoundBuffer_createFromFile
	("utils/explode.ogg");
	hunter->noise.sound = set_buffer(hunter);
	hunter->noise.music = sfMusic_createFromFile("utils/music.ogg");
}

void	init_cursor(struct game *hunter)
{
	hunter->cursor.target = sfSprite_create();
	hunter->cursor.target_texture =
	sfTexture_createFromFile("utils/target.png", NULL);
	sfSprite_setTexture(hunter->cursor.target,
	hunter->cursor.target_texture, sfTrue);
	hunter->cursor.target_pos.x = 0;
	hunter->cursor.target_pos.y = 0;
}