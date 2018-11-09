/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:09:24 by marvin            #+#    #+#             */
/*   Updated: 2018/11/09 10:11:21 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static inline float	lerp(float a, float b, float f)
{
    return (a + f * (b - a));
}

static int			anim_ants(t_list *run, float *delta_time, float *speed)
{
	t_ant			*ant;

	while (run != NULL)
	{
		ant = (t_ant *)run->content;
		ant->actual.x = lerp(ant->prev->pos.x, ant->next->pos.x, *delta_time);
		ant->actual.y = lerp(ant->prev->pos.y, ant->next->pos.y, *delta_time);
		run = run->next;
	}
	*delta_time += 0.004f + *speed;
	if (*delta_time > 1.0f || *delta_time < 0.0f)
	{
		*delta_time = *delta_time < 0.0f ? 0.01f : 0.0f;
		if (*speed == 0.0f)
		sdl_wait(200);
	}
	*speed = 0.0f;
	return (*delta_time == 0.0f ? 1 : 0);
}

void				sdl_loop(t_env *e, t_visual *v)
{
	float	delta_time;
	float	speed;

	delta_time = 0.0f;
	speed = 0.0f;
	e->actual_run = e->runs;
	v->events.options.draw = TRUE;
	while (v->events.options.exit == FALSE)
	{
		sdl_event(&v->events);
		if (v->events.options.draw == TRUE && v->events.options.pause == FALSE)
		{
			sdl_draw(e, v);
			if (e->actual_run != NULL)
			{
				if (anim_ants((t_list *)e->actual_run->content, &delta_time, &speed))
					e->actual_run = e->actual_run->next;
			}
			else
				v->events.options.draw = FALSE;
		}
		if (v->events.keys[SDL_SCANCODE_RIGHT] == TRUE)
		{
			v->events.options.pause ^= v->events.options.pause & 1;
			speed = 0.008f;
		}
		if (v->events.keys[SDL_SCANCODE_LEFT] == TRUE)
		{
			v->events.options.pause ^= v->events.options.pause & 1;
			speed = -0.008f;
		}
	}
}
