/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:03:22 by marvin            #+#    #+#             */
/*   Updated: 2018/08/17 11:46:35 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void    sdl_draw(t_env *e, t_visual *v)
{
    SDL_RenderClear(v->renderer);
    draw_all(e, v);
	SDL_RenderPresent(v->renderer);
}
