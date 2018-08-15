/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:03:22 by marvin            #+#    #+#             */
/*   Updated: 2018/08/15 17:38:05 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void    sdl_draw(t_env *e, t_visual *v)
{
    SDL_RenderClear(v->renderer);
    SDL_SetRenderDrawColor(v->renderer, rand() % 255, rand() % 255, rand() % 255, 255);


    t_list *tmp1 = e->room;
    while (tmp1)
    {
        t_coord pos1 = ((t_room *)(tmp1->content))->pos;
        t_list *links = ((t_room *)(tmp1->content))->links;
        while (links)
        {
            t_coord pos2 = ((t_room*)(links->content))->pos;
            SDL_RenderDrawLine(v->renderer, pos1.x * (WIN_W / 2), pos1.y * (WIN_H / 2), pos2.x * (WIN_W / 2), pos2.y * (WIN_H / 2));
            links = links->next;
        }
        tmp1 = tmp1->next;
    }
    t_list *tmp2 = e->room;
    while (tmp2)
    {
        t_room *room = (t_room *)tmp2->content;
        draw_fill_circle(v, room->pos.x * (WIN_W / 2), room->pos.y * (WIN_H / 2), 99);
        draw_circle(v, room->pos.x * (WIN_W / 2), room->pos.y * (WIN_H / 2), 100);
        tmp2 = tmp2->next;
    }
	SDL_RenderPresent(v->renderer);
}
