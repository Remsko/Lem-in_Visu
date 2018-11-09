/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:28:23 by marvin            #+#    #+#             */
/*   Updated: 2018/11/09 09:54:19 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include "visu.h"

typedef unsigned char	t_room_type;

typedef struct			s_screen
{
	int					width;
	int					height;
}						t_screen;

typedef struct			s_options
{
	t_bool				exit;
	t_bool				draw;
	t_bool				pause;
}						t_options;

typedef struct			s_events
{
	t_options			options;
	const unsigned char	*keys;
}						t_events;

typedef struct			s_visual
{
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	SDL_Texture			*texture;
	t_events			events;
	t_screen			screen;
}						t_visual;

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

typedef struct			s_fcoord
{
	float				x;
	float				y;
}						t_fcoord;

typedef struct			s_extremum
{
	t_coord				min;
	t_coord				max;
}						t_extremum;

typedef struct			s_color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}						t_color;

typedef struct			s_room
{
	t_list				*links;
	char				*name;
	t_coord				pos;
	t_room_type			type;
}						t_room;

typedef struct			s_ant
{
	int					nb;
	t_room				*prev;
	t_room				*next;
	t_fcoord			actual;
	t_color				color;
}						t_ant;

typedef struct			s_env
{
	int					ants;
	t_list				*anthill;
	t_list				*room;
	t_list				*runs;
	t_list				*actual_run;
}						t_env;

#endif
