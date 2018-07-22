/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 14:59:38 by marvin            #+#    #+#             */
/*   Updated: 2018/07/22 14:59:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

#include "libft.h"
#include "SDL.h"

# define WIN_W 2000
# define WIN_H 1500

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

#endif