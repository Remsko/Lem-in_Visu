/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:09:24 by marvin            #+#    #+#             */
/*   Updated: 2018/11/08 17:51:43 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

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
	static float	delta_time = 0;
	t_ant			*ant;

	while (run != NULL)
	{
		ant = (t_ant *)run->content;
		ant->actual.x = lerp(ant->prev->pos.x, ant->next->pos.x, delta_time);
		ant->actual.y = lerp(ant->prev->pos.y, ant->next->pos.y, delta_time);
		run = run->next;
	}
	delta_time += 0.005;
	if (delta_time > 1)
	{
		delta_time = 0;
		sdl_wait(100);
	}
	return (!delta_time);
}

void	sdl_loop(t_env *e, t_visual *v)
{
	e->actual_run = e->runs;
	ft_bzero(&v->events, sizeof(t_events));
	init_run((t_list *)e->actual_run->content);
	v->events.options.draw = TRUE;
	while (v->events.options.exit == FALSE)
	{
		sdl_event(&v->events);
		if (v->events.options.draw == TRUE)
		{
			sdl_draw(e, v);
			if (e->actual_run != NULL)
			{
				if (forward_ants((t_list *)e->actual_run->content))
					e->actual_run = e->actual_run->next;
			}
			else
				v->events.options.draw = FALSE;
		}
	}
}
