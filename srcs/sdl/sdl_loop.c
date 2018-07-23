/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:09:24 by marvin            #+#    #+#             */
/*   Updated: 2018/07/23 13:55:43 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void    sdl_loop(t_visual *v)
{
	ft_bzero(&v->events, sizeof(t_events));
	while (v->events.options.exit == FALSE)
	{
		sdl_fps();
		sdl_event(&v->events);
		if (v->events.options.draw == FALSE)
		{
			sdl_draw(v);
			v->events.options.draw = TRUE;
		}
	}
}
