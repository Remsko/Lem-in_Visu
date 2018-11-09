/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:27:10 by marvin            #+#    #+#             */
/*   Updated: 2018/11/09 13:44:01 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "visu.h"

t_bool	parser_entry(t_env *e);

t_bool	get_ants(t_env *e, char **line);

t_bool	get_rooms(t_env *e, char **line);

t_bool	get_links(t_env *e, char **line);

t_bool	get_runs(t_env *e, char **line);

t_ant	*find_prev(t_list *ant_list, t_ant *actual);

t_room	*find_start(t_list *room);

t_room	*find_room(t_list *room, char *name);

void	sdl_destroy(t_visual *v);

void	sdl_draw(t_env *e, t_visual *v);

void	sdl_event(t_events *e);

void	sdl_handle_event(t_visual *v, float *speed);

void	sdl_fps(void);

void	sdl_init(t_visual *v);

void	sdl_loop(t_env *e, t_visual *v);

void	sdl_wait(unsigned int wait);

double	sdl_frametime(void);

void	garbage_collector(t_env *e);

void	del_str(void *content, size_t content_size);

void	del_nothing(void *content, size_t content_size);

void	del_room(void *content, size_t content_size);

void	del_ant(void *content, size_t content_size);

void	del_runs(void *content, size_t content_size);

void	draw_circle(t_visual *v, int x0, int y0, int r);

void	draw_fill_circle(t_visual *v, int x0, int y0, int r);

void	draw_line(t_visual *v, int x1, int y1, int x2, int y2);

void	draw_all(t_env *e, t_visual *v);

void	normalize_coord(t_list *room);

#endif
