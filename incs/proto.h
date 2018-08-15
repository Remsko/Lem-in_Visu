/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:27:10 by marvin            #+#    #+#             */
/*   Updated: 2018/08/15 17:09:47 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "visu.h"

/* PARSER */

t_bool  parser_entry(t_env *e);

t_bool  get_ants(t_env *e, char **line);

t_bool  get_rooms(t_env *e, char **line);

t_bool  get_links(t_env *e, char **line);

/* SDL */

void	sdl_destroy(t_visual *v);

void    sdl_draw(t_env *e, t_visual *v);

void	sdl_event(t_events *e);

void	sdl_fps(void);

void    sdl_init(t_visual *v);

void    sdl_loop(t_env *e, t_visual *v);

/* DEL */

void	garbage_collector(t_env *e);

void    del_str(void *content, size_t content_size);

void    del_nothing(void *content, size_t content_size);

void    del_room(void *content, size_t content_size);

/* DRAW */

void draw_circle(t_visual *v, int x0, int y0, int r);

void draw_fill_circle(t_visual *v, int x0, int y0, int r);

#endif
