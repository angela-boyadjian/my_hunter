/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main function
*/
#include "my_hunter.h"

sfSound *set_buffer(struct game *hunter)
{
	hunter->noise.sound = sfSound_create();
	sfSound_setBuffer(hunter->noise.sound, hunter->noise.buffer);
	return (hunter->noise.sound);
}

int	my_hunter(struct game *hunter, sfRenderWindow *window)
{
	static int	speed = 30;

	hunter->gear.time = sfClock_getElapsedTime(hunter->gear.clock);
	hunter->gear.seconds = hunter->gear.time.microseconds / 1000000.0;
	handle_event(window, hunter);
	if (hunter->score.hits > 4 || hunter->score.lives <= 0) {
		end_game(window, hunter, hunter->score.lives);
		return (1);
	}
	if (hunter->gear.seconds > 0.1) {
		hunter->tools.pos.x += speed;
		hunter->tools_2.pos.x += speed;
		handle_sprites(hunter, window);
		handle_text(hunter, window, hunter->score.hits,
		hunter->score.lives);
		sfRenderWindow_display(window);
		sfClock_restart(hunter->gear.clock);
		hunter->gear.seconds = 0.0;
	}
	return (0);
}

static void	destroy_utils(sfRenderWindow *window, struct game *hunter)
{
	sfSoundBuffer_destroy(hunter->noise.buffer);
	sfMusic_destroy(hunter->noise.music);
	sfSound_destroy(hunter->noise.sound);
	sfText_destroy(hunter->score.text);
	sfFont_destroy(hunter->score.font);
	sfRenderWindow_clear(window, sfBlack);
	sfRenderWindow_destroy(window);
}

int	help(int ac, char **av)
{
	for (int i = 0; i < ac; ++i) {
		if (my_strcmp(av[i], "-h") == 0) {
			my_printf("%s%s%s%s%s", U1, U2, U3, U4, U5);
			return (1);
		}
	}
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	struct game	hunter;
	sfEvent		event;
	sfRenderWindow	*window;
	int		value = errors(ac, av, envp);

	if (value == 84 || value == 0 || get_size(ac, av, &hunter) == 84)
		return (value);
	init_game(&hunter);
	window = create_my_window(&hunter);
	create_text(&hunter, 30, "score", 1);
	sfRenderWindow_setFramerateLimit(window, 60);
	sfMusic_play(hunter.noise.music);
	sfMusic_setLoop(hunter.noise.music, sfTrue);
	while (sfRenderWindow_isOpen(window)) {
		if (my_hunter(&hunter, window) == 1) {
			reset_game(&hunter, window, event);
		}
	}
	destroy_utils(window, &hunter);
	return (0);
}