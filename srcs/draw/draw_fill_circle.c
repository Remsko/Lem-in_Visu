/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fill_circle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 17:05:25 by rpinoit           #+#    #+#             */
/*   Updated: 2018/08/15 17:05:26 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void draw_fill_circle(t_visual *v, int x0, int y0, int r)
{
    // BRUTEFORCE
    /*
    int r2 = r * r;
    int area = r2 << 2;
    int rr = r << 1;

    SDL_SetRenderDrawColor(v->renderer, rand() % 255, rand() % 255, rand() % 255, 255);
    for (int i = 0; i < area; i++)
    {
    int tx = (i % rr) - r;
    int ty = (i / rr) - r;

    if (tx * tx + ty * ty <= r2)
        SDL_RenderDrawPoint(v->renderer, x0 + tx, y0 + ty);
    }
    */
    // Bresenham's algorithm
    int x = r;
    int y = 0;
    int xChange = 1 - (r << 1);
    int yChange = 0;
    int radiusError = 0;

    SDL_SetRenderDrawColor(v->renderer, rand() % 255, rand() % 255, rand() % 255, 255);
    while (x >= y)
    {
        for (int i = x0 - x; i <= x0 + x; i++)
        {
            SDL_RenderDrawPoint(v->renderer, i, y0 + y);
            SDL_RenderDrawPoint(v->renderer, i, y0 - y);
        }
        for (int i = x0 - y; i <= x0 + y; i++)
        {
            SDL_RenderDrawPoint(v->renderer, i, y0 + x);
            SDL_RenderDrawPoint(v->renderer, i, y0 - x);
        }
        y++;
        radiusError += yChange;
        yChange += 2;
        if (((radiusError << 1) + xChange) > 0)
        {
            x--;
            radiusError += xChange;
            xChange += 2;
        }
    }
}