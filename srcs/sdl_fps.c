/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_fps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:07:45 by marvin            #+#    #+#             */
/*   Updated: 2018/07/22 15:07:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	sdl_fps(void)
{
	static int			fps;
	static unsigned int	last_time;
	unsigned int		current_time;

	++fps;
	current_time = SDL_GetTicks();
	if (current_time > last_time + (unsigned int)1000)
	{
		ft_putstr("fps: ");
		ft_putnbr(fps);
		ft_putchar('\n');
		fps = 0;
		last_time = current_time;
	}
}