/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:00:18 by rpinoit           #+#    #+#             */
/*   Updated: 2018/08/17 12:0:03 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void get_extremum(t_list *room, t_extremum *ext)
{
    t_coord pos;

    while (room != NULL)
    {
        pos = ((t_room *)room->content)->pos;
        if (pos.x > ext->max.x)
            ext->max.x = pos.x;
        if (pos.y > ext->max.y)
            ext->max.y = pos.y;
        if (pos.x < ext->min.x)
            ext->min.x = pos.x;
        if (pos.y < ext->min.y)
            ext->min.y = pos.y;
        room = room->next;
    }
}

void normalize_coord(t_list *room)
{
    t_extremum  ext;
    t_coord     *pos;

    ext.min.x = 0x7FFFFFFF;
    ext.min.x = 0x7FFFFFFF;
    ext.max.x = -0x7FFFFFFF;
    ext.max.y = -0x7FFFFFFF;
    get_extremum(room, &ext);
    while (room != NULL)
    {
        pos = &((t_room *)room->content)->pos;
        pos->x = WIN_W / 10 + ((double)(pos->x - ext.min.x) / (double)(ext.max.x - ext.min.x)) * (double)(WIN_W - (WIN_W / 10 * 2));
        pos->y = WIN_H / 10 + ((double)(pos->y - ext.min.y) / (double)(ext.max.y - ext.min.y)) * (double)(WIN_H - (WIN_H / 10 * 2));
        room = room->next;
    }
}