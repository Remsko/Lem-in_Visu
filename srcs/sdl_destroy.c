/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:02:21 by marvin            #+#    #+#             */
/*   Updated: 2018/07/22 15:02:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	sdl_destroy(t_visual *v)
{
	SDL_DestroyTexture(v->texture);
	SDL_DestroyRenderer(v->renderer);
	SDL_DestroyWindow(v->window);
	SDL_Quit();
}