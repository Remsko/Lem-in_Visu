/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 11:03:47 by rpinoit           #+#    #+#             */
/*   Updated: 2018/08/17 11:46:28 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void draw_links(t_list *room, t_visual *v)
{
    t_list  *links;
    t_room  *room1;
    t_room  *room2;
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
            draw_line(v, pos1.x * (WIN_W / 2), pos1.y * (WIN_H / 2), pos2.x * (WIN_W / 2), pos2.y * (WIN_H / 2));
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
        draw_fill_circle(v, tmp->pos.x * (WIN_W / 2), tmp->pos.y * (WIN_H / 2), 102);
        draw_fill_circle(v, tmp->pos.x * (WIN_W / 2), tmp->pos.y * (WIN_H / 2), 100);
        room = room->next;
    }
}

void        draw_all(t_env *e, t_visual *v)
{
    draw_links(e->room, v);
    draw_rooms(e->room, v);
}