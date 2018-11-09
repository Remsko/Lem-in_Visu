/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:40:11 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/09 13:45:55 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

t_ant	*find_prev(t_list *ant_list, t_ant *actual)
{
	t_ant	*ant;

	while (ant_list != NULL)
	{
		ant = (t_ant *)ant_list->content;
		if (ant->nb == actual->nb)
			return (ant);
		ant_list = ant_list->next;
	}
	return (NULL);
}

t_room	*find_start(t_list *room)
{
	t_room *tmp;

	while (room != NULL)
	{
		tmp = (t_room *)room->content;
		if (tmp->type == START)
			return (tmp);
		room = room->next;
	}
	return (NULL);
}

t_room	*find_room(t_list *room, char *name)
{
	t_room *tmp;

	if (name == NULL)
		return (NULL);
	while (room != NULL)
	{
		tmp = (t_room *)room->content;
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp);
		room = room->next;
	}
	return (NULL);
}
