/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:09:24 by marvin            #+#    #+#             */
/*   Updated: 2018/11/08 20:27:22 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static inline float	lerp(float a, float b, float f)
{
    return (a + f * (b - a));
}

static int			forward_ants(t_list *run, float *delta_time)
{
	t_ant			*ant;

	while (run != NULL)
	{
		ant = (t_ant *)run->content;
		ant->actual.x = lerp(ant->prev->pos.x, ant->next->pos.x, *delta_time);
		ant->actual.y = lerp(ant->prev->pos.y, ant->next->pos.y, *delta_time);
		run = run->next;
	}
	*delta_time += 0.004;
	if (*delta_time > 1)
	{
		*delta_time = 0.0;
		sdl_wait(200);
	}
	return (*delta_time == 0.0 ? 1 : 0);
}

void				sdl_loop(t_env *e, t_visual *v)
{
	float delta_time;

	delta_time = 0;
	e->actual_run = e->runs;
	v->events.options.draw = TRUE;
	while (v->events.options.exit == FALSE)
	{
		sdl_event(&v->events);
		if (v->events.options.draw == TRUE)
		{
			sdl_draw(e, v);
			if (e->actual_run != NULL)
			{
				if (forward_ants((t_list *)e->actual_run->content, &delta_time))
					e->actual_run = e->actual_run->next;
			}
			else
				v->events.options.draw = FALSE;
		}
		if (v->events.keys[SDL_SCANCODE_RIGHT] == TRUE)
			if (e->actual_run != NULL && e->actual_run->next != NULL)
			{
				e->actual_run = e->actual_run->next;
				delta_time = 0;
				forward_ants((t_list *)e->actual_run->content, &delta_time);
				sdl_draw(e, v);
				sdl_wait(200);
			}
		if (v->events.keys[SDL_SCANCODE_LEFT] == TRUE)
		{
			t_list *tmp = e->runs;
			while (tmp->next != NULL)
			{
				if (tmp->next == e->actual_run)
				{
					e->actual_run = tmp;
					delta_time = 0;
					forward_ants((t_list *)e->actual_run->content, &delta_time);
					sdl_draw(e, v);
					sdl_wait(200);
					break ;
				}
				tmp = tmp->next;
			}
		}
	}
}
