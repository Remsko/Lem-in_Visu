/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:09:24 by marvin            #+#    #+#             */
/*   Updated: 2018/11/08 15:36:11 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

double get_frametime(void)
{
	static unsigned int time;
	static unsigned int old;

	old = time;
	time = SDL_GetTicks();
	return ((time - old) / 1000.0);
}

void	init_run(t_list	*run)
{
	t_ant	*ant;

	while (run != NULL)
	{
		ant = run->content;
		ant->actual.x = (float)ant->prev->pos.x;
		ant->actual.y = (float)ant->prev->pos.y;
		run = run->next;
	}
}

float lerp(float a, float b, float f)
{
    return (a + f * (b - a));
}

int	forward_ants(t_list	*run)
{
	t_ant	*ant;
	static float delta_time = 0;

	while (run != NULL)
	{
		ant = run->content;
		ant->actual.x = lerp(ant->prev->pos.x, ant->next->pos.x, delta_time);
		ant->actual.y = lerp(ant->prev->pos.y, ant->next->pos.y, delta_time);
		run = run->next;
	}
	delta_time += 0.003;
	if (delta_time > 1)
	{
		delta_time = 0;
		int time = SDL_GetTicks(); 
		while (SDL_GetTicks() - time < 100)
			;
		return (1);
	}
	return (0);
}

void	draw_ants(t_visual *v, t_list *run)
{
	t_ant	*ant;

	while (run != NULL)
	{
		ant = (t_ant *)run->content;
		SDL_SetRenderDrawColor(v->renderer, ant->color.r, ant->color.g, ant->color.b, 255);
		draw_fill_circle(v, ant->actual.x, ant->actual.y, 5);
		run = run->next;
	}
}

void	sdl_loop(t_env *e, t_visual *v)
{
	t_list	*runs;

	runs = e->runs;
	ft_bzero(&v->events, sizeof(t_events));
	init_run((t_list *)runs->content);
	while (v->events.options.exit == FALSE)
	{
		sdl_fps();
		sdl_event(&v->events);
		/*
		if (v->events.options.draw == FALSE)
		{
			sdl_draw(e, v);
			v->events.options.draw = TRUE;
		}
		*/
		sdl_draw(e, v);
		if (runs)
		{
			draw_ants(v, (t_list *)runs->content);
			if (forward_ants((t_list *)runs->content/*, get_frametime()*/))
				runs = runs->next;
		}
		SDL_RenderPresent(v->renderer);
	}
}
