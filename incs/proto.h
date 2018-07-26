/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:27:10 by marvin            #+#    #+#             */
/*   Updated: 2018/07/26 20:34:36 by rpinoit          ###   ########.fr       */
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

void    sdl_draw(t_visual *v);

void	sdl_event(t_events *e);

void	sdl_fps(void);

void    sdl_init(t_visual *v);

void    sdl_loop(t_visual *v);

#endif
