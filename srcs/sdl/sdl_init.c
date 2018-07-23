/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:08:23 by marvin            #+#    #+#             */
/*   Updated: 2018/07/23 13:49:19 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void		sdl(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		exit(-1);
	}
}

static void		window(t_visual *v)
{
	if ((v->window = SDL_CreateWindow(
					"Lem-in Visu",
					SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED,
					v->screen.width,
					v->screen.height,
					0)) == NULL)
	{
        SDL_Log("Unable to create window: %s", SDL_GetError());
		exit(-2);
	}
}

static void		image(t_visual *v)
{
	if ((v->renderer = SDL_CreateRenderer(v->window,
					-1,
					SDL_RENDERER_SOFTWARE)) == NULL)
	{
        SDL_Log("Unable to create renderer: %s", SDL_GetError());
		exit(-3);
	}
}

static void		texture(t_visual *v)
{
	if ((v->texture = SDL_CreateTexture(v->renderer,
					SDL_PIXELFORMAT_RGBA8888,
					SDL_TEXTUREACCESS_TARGET,
					v->screen.width,
					v->screen.height)) == NULL)
	{
		SDL_Log("Unable to create texture: %s", SDL_GetError());
		exit(-4);
	}
}

void			sdl_init(t_visual *v)
{
	sdl();
	window(v);
	image(v);
	texture(v);
}
