/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:11:32 by marvin            #+#    #+#             */
/*   Updated: 2018/11/08 11:30:50 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		main(int ac, char **av)
{
	t_visual	v;
	t_env		e;

	(void)av;
	v.screen.width = WIN_W;
	v.screen.height = WIN_H;
	ft_bzero(&e, sizeof(t_env));
	if (ac == 1)
	{
		if (parser_entry(&e) == FALSE)
		{
			ft_putendl("ERROR");
			return (1);
		}
		normalize_coord(e.room);
		///*
		sdl_init(&v);
		sdl_loop(&e, &v);
		sdl_destroy(&v);
		//*/
		/*
		t_list *tmp = e.runs;
		while (tmp != NULL)
		{
			t_list *tmp2 = (t_list *)tmp->content;
			while (tmp2 != NULL)
			{
				printf("%d ", (int)(((t_ant *)(tmp2->content))->nb));
				tmp2 = tmp2->next;
			}
			printf("\n");
			tmp = tmp->next;
		}
		*/
		garbage_collector(&e);
	}
	else
		ft_putendl("usage: ./lem-in <anthill's path> | ./visu");
	return (0);
}
