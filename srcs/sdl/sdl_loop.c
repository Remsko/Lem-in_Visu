/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:09:24 by marvin            #+#    #+#             */
/*   Updated: 2018/08/15 14:14:56 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void    sdl_loop(t_env *e, t_visual *v)
{
	ft_bzero(&v->events, sizeof(t_events));
	while (v->events.options.exit == FALSE)
	{
		sdl_fps();
		sdl_event(&v->events);
		if (v->events.options.draw == FALSE)
		{
			sdl_draw(e, v);
			v->events.options.draw = TRUE;
		}
	}
}
