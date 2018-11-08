/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:29:36 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/08 17:04:12 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void sdl_wait(unsigned int wait)
{
    unsigned int time;

    time = SDL_GetTicks();
    while (SDL_GetTicks() - time < wait)
        ;
}

double sdl_frametime(void)
{
    static unsigned int time[2];

    time[1] = time[0];
    time[0] = SDL_GetTicks();
    return ((double)(time[0] - time[1]) * 0.001);
}