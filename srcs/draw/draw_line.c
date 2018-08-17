/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 17:14:48 by rpinoit           #+#    #+#             */
/*   Updated: 2018/08/17 15:49:04 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	draw_line(t_visual *v, int x1, int y1, int x2, int y2)
{
	int dx;
	int dy;
	int eps;

	dx = x2 - x1;
	dy = y2 - y1;
	eps = 0;
	SDL_SetRenderDrawColor(v->renderer, 200, 200, 200, 255);
	while (x1 <= x2)
	{
		SDL_RenderDrawPoint(v->renderer, x1, y1);
		eps += dy;
		if ((eps << 1) >= dx)
		{
			++y1;
			eps -= dx;
		}
		++x1;
	}
}
