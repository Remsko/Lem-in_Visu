/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 17:05:00 by rpinoit           #+#    #+#             */
/*   Updated: 2018/08/17 15:44:42 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	draw_circle(t_visual *v, int x0, int y0, int r)
{
	int x;
	int y;
	int p;

	x = 0;
	y = r;
	p = 3 - (2 * r);
	SDL_SetRenderDrawColor(v->renderer, rand() % 255, rand() % 255, rand() % 255, 255);
	SDL_RenderDrawPoint(v->renderer, x0 + x, y0 - y);
	while (x <= y)
	{
		if (p < 0)
			p = (p + (4 * x) + 6);
		else
		{
			y = y - 1;
			p = p + ((4 * (x - y) + 10));
		}
		SDL_RenderDrawPoint(v->renderer, x0 + x, y0 - y);
		SDL_RenderDrawPoint(v->renderer, x0 - x, y0 - y);
		SDL_RenderDrawPoint(v->renderer, x0 + x, y0 + y);
		SDL_RenderDrawPoint(v->renderer, x0 - x, y0 + y);
		SDL_RenderDrawPoint(v->renderer, x0 + y, y0 - x);
		SDL_RenderDrawPoint(v->renderer, x0 - y, y0 - x);
		SDL_RenderDrawPoint(v->renderer, x0 + y, y0 + x);
		SDL_RenderDrawPoint(v->renderer, x0 - y, y0 + x);
		++x;
	}
}
