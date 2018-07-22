/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:09:24 by marvin            #+#    #+#             */
/*   Updated: 2018/07/22 15:09:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void    sdl_loop(t_visual *v)
{
	ft_bzero(&v->events, sizeof(t_events));
	while (e->events.options.exit == FALSE)
	{
		sdl_fps();
		sdl_event(&v->events);
	}
}