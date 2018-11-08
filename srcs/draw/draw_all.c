/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 11:03:47 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/08 17:47:29 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void draw_links(t_list *room, t_visual *v)
{
    t_room *room1;
    t_room *room2;
    t_list *links;
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

static void chose_color(t_visual *v, t_room_type type)
{
    if (type == START)
        SDL_SetRenderDrawColor(v->renderer, 108, 215, 108, 255);
    else if (type == END)
        SDL_SetRenderDrawColor(v->renderer, 153, 0, 51, 255);
    else
        SDL_SetRenderDrawColor(v->renderer, 115, 194, 251, 255);
}

static void draw_rooms(t_list *room, t_visual *v)
{
    t_room *tmp;

    while (room != NULL)
    {
        tmp = (t_room *)room->content;
        SDL_SetRenderDrawColor(v->renderer, 255, 255, 255, 255);
        draw_fill_circle(v, tmp->pos.x, tmp->pos.y, 23);
        chose_color(v, tmp->type);
        draw_fill_circle(v, tmp->pos.x, tmp->pos.y, 21);
        room = room->next;
    }
}

static void	draw_ants(t_visual *v, t_list *run)
{
	t_ant	*ant;

	while (run != NULL)
	{
		ant = (t_ant *)run->content;
		SDL_SetRenderDrawColor(v->renderer, ant->color.r, ant->color.g, ant->color.b, 255);
		draw_fill_circle(v, ant->actual.x, ant->actual.y, 5);
		run = run->next;
	}
}

void draw_all(t_env *e, t_visual *v)
{
    SDL_SetRenderDrawColor(v->renderer, 82, 85, 100, 255);
    if (e->room != NULL)
    {
        draw_links(e->room, v);
        draw_rooms(e->room, v);
    }
    if (e->actual_run != NULL)
        draw_ants(v, (t_list *)e->actual_run->content);
}
