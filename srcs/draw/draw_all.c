/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 11:03:47 by rpinoit           #+#    #+#             */
/*   Updated: 2018/08/17 14:22:29 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void draw_links(t_list *room, t_visual *v)
{
    t_room  *room1;
    t_room  *room2;
    t_list  *links;
    t_coord pos1;
    t_coord pos2;

    while (room != NULL)
    {
        room1 = (t_room *)room->content; 
        pos1 = room1->pos;
        links = room1->links;
        while (links != NULL)
        {
            room2 = (t_room *)links->content; 
            pos2 = room2->pos;
            SDL_RenderDrawLine(v->renderer, pos1.x - 1, pos1.y, pos2.x, pos2.y);
            SDL_RenderDrawLine(v->renderer, pos1.x + 1, pos1.y, pos2.x, pos2.y);
            SDL_RenderDrawLine(v->renderer, pos1.x, pos1.y + 1, pos2.x, pos2.y);
            SDL_RenderDrawLine(v->renderer, pos1.x, pos1.y - 1, pos2.x, pos2.y);
            SDL_RenderDrawLine(v->renderer, pos1.x, pos1.y, pos2.x + 1, pos2.y);
            SDL_RenderDrawLine(v->renderer, pos1.x, pos1.y, pos2.x - 1, pos2.y);
            SDL_RenderDrawLine(v->renderer, pos1.x, pos1.y, pos2.x, pos2.y + 1);
            SDL_RenderDrawLine(v->renderer, pos1.x, pos1.y, pos2.x, pos2.y - 1);
            links = links->next;
        }
        room = room->next;
    }
}

static void draw_rooms(t_list *room, t_visual *v)
{
    t_room *tmp;

    while (room != NULL)
    {
        tmp = (t_room *)room->content;
        SDL_SetRenderDrawColor(v->renderer, 255, 255, 255, 255);
        draw_fill_circle(v, tmp->pos.x, tmp->pos.y, 20);
        SDL_SetRenderDrawColor(v->renderer, 115, 194, 251, 255);
        draw_fill_circle(v, tmp->pos.x, tmp->pos.y, 18);
        room = room->next;
    }
}

void draw_all(t_env *e, t_visual *v)
{
    SDL_SetRenderDrawColor(v->renderer, 155, 155, 155, 255);
    draw_links(e->room, v);
    draw_rooms(e->room, v);
}