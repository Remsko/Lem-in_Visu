/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_handle_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:58:24 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/09 12:02:08 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	sdl_handle_event(t_visual *v, float *speed)
{
	if (v->events.keys[SDL_SCANCODE_RIGHT] == TRUE)
	{
		v->events.options.pause ^= v->events.options.pause & 1;
		*speed = 0.008f;
	}
	if (v->events.keys[SDL_SCANCODE_LEFT] == TRUE)
	{
		v->events.options.pause ^= v->events.options.pause & 1;
		*speed = -0.008f;
	}
}
