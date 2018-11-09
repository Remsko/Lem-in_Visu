/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:04:23 by marvin            #+#    #+#             */
/*   Updated: 2018/11/09 10:09:54 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	sdl_event(t_events *e)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			e->options.exit = TRUE;
		else if (event.key.keysym.sym == SDLK_ESCAPE)
			e->options.exit = TRUE;
		else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
			e->options.pause ^= 1;
		else
			e->keys = SDL_GetKeyboardState(NULL);
	}
}
