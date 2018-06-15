/*
** EPITECH PROJECT, 2017
** events.c
** File description:
** events handling
*/
#include "my_hunter.h"

static void window_close(sfRenderWindow *window)
{
	sfRenderWindow_close(window);
}

static int manage_key(sfKeyEvent key)
{
	if (key.code == sfKeySpace)
		return (1);
	return (0);
}

static int manage_mouse_click(sfMouseButtonEvent event, struct images *tools)
{
	if (event.button == sfMouseLeft && (((event.x <
	(tools->pos.x + 80) && event.x > tools->pos.x - 80))
	&& (event.y > (tools->pos.y - 80)
	&& event.y < tools->pos.y + 80)))
		return (1);
	return (0);
}

void	handle_event(sfRenderWindow *window, struct game *hunter)
{
	sfEvent	event;

	if (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtMouseMoved) {
			hunter->cursor.target_pos.x = event.mouseMove.x;
			hunter->cursor.target_pos.y = event.mouseMove.y;
		}
		if (set_pos(&(hunter->tools), window, event, hunter) == 1 ||
			set_pos(&(hunter->tools_2), window, event, hunter)
			== 1)
			hunter->score.hits = hunter->score.hits + 1;
		else if (set_pos(&(hunter->tools), window, event, hunter)
		== -1 && set_pos(&(hunter->tools_2), window, event, hunter)
		== -1)
			hunter->score.lives = hunter->score.lives - 1;
	}
}

int analyse_events(sfRenderWindow *window, sfEvent event, struct game *hunter,
	struct images *tools)
{
	if (event.type == sfEvtMouseButtonPressed) {
		sfSound_play(hunter->noise.sound);
		if (manage_mouse_click(event.mouseButton, tools) == 1)
			return (1);
		return (-1);
	}
	if (event.type == sfEvtKeyPressed && manage_key(event.key) == 1)
		return (2);
	if (event.type == sfEvtClosed)
		window_close(window);
	return (0);
}