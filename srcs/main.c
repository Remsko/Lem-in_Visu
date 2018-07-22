/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:11:32 by marvin            #+#    #+#             */
/*   Updated: 2018/07/22 15:11:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int     main(int ac, char **av)
{
	t_visual    v;

	v.screen.width = WIN_W;
	v.screen.height = WIN_H;
	if (ac == 1)
	{
		sdl_init(&v);
		sdl_loop(&e, &v);
		sdl_destroy(&v);
	}
	else
		ft_putendl("usage: ./lem-in <anthill's path> | ./visu");
	return (0);
}