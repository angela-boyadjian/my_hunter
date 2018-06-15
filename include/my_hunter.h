/*
** EPITECH PROJECT, 2017
** my_hunter.h
** File description:
** hunter header
*/
#ifndef MY_HUNTER_H
#define MY_HUNTER_H

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <stddef.h>
#include "print.h"

struct	music {
	sfSoundBuffer	*buffer;
	sfSound		*sound;
	sfMusic		*music;;
};

struct	text {
	sfText		*text;
	sfVector2f	text_pos;
	sfFont		*font;
	int		lives;
	int		hits;
};

struct	times	{
	sfClock		*clock;
	sfTime		time;
	float		seconds;
};

struct	target {
	sfSprite	*target;
	sfTexture	*target_texture;
	sfVector2f	target_pos;
};

struct	images {
	sfSprite	*spritesheet;
	sfSprite	*background;
	sfTexture	*spritesheet_texture;
	sfTexture	*background_texture;
	sfIntRect	spritesheet_rect;
	sfVector2f	pos;
	sfVector2f	init_pos;
};

struct game {
	struct images	tools;
	struct images	tools_2;
	struct times	gear;
	struct text	score;
	struct music	noise;
	struct target	cursor;
	int		height;
	int		width;
};

sfRenderWindow *create_my_window(struct game *hunter);
sfSound		*set_buffer(struct game *hunter);
void init_times(struct game *hunter);
void init_images_2(struct game *hunter);
void init_images(struct game *hunter);
void set_texture(struct game *hunter);
void init_noise(struct game *hunter);
void init_cursor(struct game *hunter);
void move_rect(sfIntRect *spritesheet_rect, int offset, int max_value);
void init_game(struct game *hunter);
void handle_ext(struct game *hunter, sfRenderWindow *window, int hits,
int lives);
void create_text(struct game *hunter, int size, char *str, int color);
void handle_sprites(struct game *hunter, sfRenderWindow *window);
void end_game(sfRenderWindow * window, struct game *hunter, int win);
void reset_game(struct game *hunter, sfRenderWindow *window, sfEvent event);
void handle_event(sfRenderWindow *window, struct game *hunter);
void init_text(struct game *hunter);
int get_size(int ac, char **av, struct game *hunter);
int my_hunter(struct game *hunter, sfRenderWindow *window);
int help(int ac, char **av);
int errors(int ac, char **av, char **envp);
int set_pos(struct images *tools, sfRenderWindow *window, sfEvent event,
struct game *hunter);
int analyse_events(sfRenderWindow *window, sfEvent event,
struct game *hunter, struct images *tools);
void text_score(struct game *hunter,
sfRenderWindow *window, int hits);
void text_lives(struct game *hunter,
sfRenderWindow *window, int lives);
void handle_text(struct game *hunter, sfRenderWindow *window,
int hits, int lives);

#endif