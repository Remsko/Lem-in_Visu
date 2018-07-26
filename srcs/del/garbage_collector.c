/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 21:23:55 by rpinoit           #+#    #+#             */
/*   Updated: 2018/07/26 21:28:27 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	garbage_collector(t_env *e)
{
	ft_lstdel(&e->anthill, &del_str);
	ft_lstdel(&e->room, &del_room);
	ft_lstdel(&e->links, &del_nothing);
}
