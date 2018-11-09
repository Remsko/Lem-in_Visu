/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fill_circle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 17:05:25 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/09 11:35:10 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	fill_loops(t_visual *v, t_coord *pos, int x0, int y0)
{
	int i;

	i = x0 - pos->x;
	while (i <= x0 + pos->x)
	{
		SDL_RenderDrawPoint(v->renderer, i, y0 + pos->y);
		SDL_RenderDrawPoint(v->renderer, i, y0 - pos->y);
		++i;
	}
	i = x0 - pos->y;
	while (i <= x0 + pos->y)
	{
		SDL_RenderDrawPoint(v->renderer, i, y0 + pos->x);
		SDL_RenderDrawPoint(v->renderer, i, y0 - pos->x);
		++i;
	}
}

void		draw_fill_circle(t_visual *v, int x0, int y0, int r)
{
	t_coord pos;
	t_coord change;
	int		err;

	pos.x = r;
	pos.y = 0;
	change.x = 1 - (r << 1);
	change.y = 0;
	err = 0;
	while (pos.x >= pos.y)
	{
		fill_loops(v, &pos, x0, y0);
		++pos.y;
		err += change.y;
		change.y += 2;
		if (((err << 1) + change.x) > 0)
		{
			--pos.x;
			err += change.x;
			change.x += 2;
		}
	}
}
