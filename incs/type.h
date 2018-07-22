/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:28:23 by marvin            #+#    #+#             */
/*   Updated: 2018/07/22 15:28:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include "visu.h"

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
	t_screen            screen;
}                       t_visual;

typedef struct          s_env;
{

}                       t_env;

#endif