/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:28:23 by marvin            #+#    #+#             */
/*   Updated: 2018/07/26 20:55:14 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include "visu.h"

typedef unsigned char   t_room_type;

typedef struct          s_screen
{
	int                 width;
	int                 height;
}                       t_screen;

typedef struct          s_options
{
	t_bool              exit;
	t_bool              draw;
}                       t_options;

typedef struct          s_events
{
	t_options           options;
	const unsigned char	*keys;
}                       t_events;

typedef struct          s_visual
{
	SDL_Window          *window;
	SDL_Renderer        *renderer;
	SDL_Texture         *texture;
	t_events			events;
	t_screen            screen;
}                       t_visual;

typedef struct  s_coord
{
	int x;
	int y;
}               t_coord;

typedef struct  s_room
{
	char            *name;
	t_coord         pos;
	t_room_type     type;
}               t_room;

typedef struct          s_env
{
	int					ants;
	t_list				*anthill;
	t_list				*room;
	t_list				*links;
}                       t_env;

#endif
