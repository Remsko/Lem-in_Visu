/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:03:22 by marvin            #+#    #+#             */
/*   Updated: 2018/07/22 15:03:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void    sdl_draw(t_visual *v)
{
    SDL_RenderClear(v->renderer);
    SDL_SetRenderDrawColor(v->renderer, 0, 0, 0, 255);
	SDL_RenderPresent(v->renderer);
}