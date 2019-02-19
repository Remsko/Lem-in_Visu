/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:11:32 by marvin            #+#    #+#             */
/*   Updated: 2019/02/19 13:52:17 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int			main(int ac, char **av)
{
	t_visual	v;
	t_env		e;

	(void)av;
	ft_bzero((void *)&e, sizeof(t_env));
	ft_bzero((void *)&v, sizeof(t_visual));
	v.screen.width = WIN_W;
	v.screen.height = WIN_H;
	if (ac == 1)
	{
		if (parser_entry(&e) == FALSE)
		{
			ft_putendl("ERROR");
			return (1);
		}
		normalize_coord(e.room);
		sdl_init(&v);
		sdl_loop(&e, &v);
		sdl_destroy(&v);
		garbage_collector(&e);
	}
	else
		ft_putendl("usage: ./lem-in <anthill's path> | ./visu");
	return (0);
}
