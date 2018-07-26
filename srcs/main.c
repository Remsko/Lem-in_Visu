/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:11:32 by marvin            #+#    #+#             */
/*   Updated: 2018/07/26 21:53:57 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int     main(int ac, char **av)
{
	t_visual    v;
    t_env       e;

	(void)av;
	v.screen.width = WIN_W;
	v.screen.height = WIN_H;
	e = (t_env){0, NULL, NULL, NULL};
	if (ac == 1)
	{
        if (parser_entry(&e) == FALSE)
		{
         	ft_putendl("ERROR");
		 	return (1);
		}
		sdl_init(&v);
		sdl_loop(&v);
		sdl_destroy(&v);
		garbage_collector(&e);
	}
	else
		ft_putendl("usage: ./lem-in <anthill's path> | ./visu");
	return (0);
}
