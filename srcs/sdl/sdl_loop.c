/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:09:24 by marvin            #+#    #+#             */
/*   Updated: 2018/11/07 18:21:06 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
/*
static double get_frametime(void)
{
	static unsigned int time;
	static unsigned int old;

	old = time;
	time = SDL_GetTicks();
	return ((time - old) / 1000.0);
}
*/
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

void	forward_ants(t_list	*run)
{
	t_ant	*ant;

	static float poulet = 0;
	while (run != NULL)
	{
		ant = run->content;
		ant->actual.x = lerp(ant->prev->pos.x, ant->next->pos.x, poulet);
		ant->actual.y = lerp(ant->prev->pos.y, ant->next->pos.y, poulet);
		run = run->next;
	}
	poulet += 0.001;
}

void	draw_ants(t_visual *v, t_list *run)
{
	t_ant	*ant;

	while (run != NULL)
	{
		ant = run->content;
		SDL_SetRenderDrawColor(v->renderer, ant->color.r, ant->color.g, ant->color.b, 255);
		draw_fill_circle(v, ant->actual.x, ant->actual.y, 10);
		run = run->next;
	}
	SDL_RenderPresent(v->renderer);
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
		if (v->events.options.draw == FALSE)
		{
			sdl_draw(e, v);
			v->events.options.draw = TRUE;
		}
		sdl_draw(e, v);
		draw_ants(v, (t_list *)runs->content);
		forward_ants((t_list *)runs->content);
	}
}
