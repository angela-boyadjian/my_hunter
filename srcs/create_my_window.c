/*
** EPITECH PROJECT, 2017
** create_my_window.c
** File description:
** creates a window
*/
#include "my_hunter.h"

sfRenderWindow *create_my_window(struct game *hunter)
{
	sfRenderWindow	*window;
	sfVideoMode	video_mode;

	video_mode.width = hunter->width;
	video_mode.height = hunter->height;
	video_mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(video_mode, "MyWindow",
		sfDefaultStyle, NULL);
	sfRenderWindow_setMouseCursorVisible(window, sfFalse);
	return (window);
}