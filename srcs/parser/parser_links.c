/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 21:29:47 by rpinoit           #+#    #+#             */
/*   Updated: 2018/08/15 17:22:09 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

t_bool   same_link(t_list *link, t_room *room)
{
	while (link)
	{
		if ((t_room*)link->content == room)
			return (TRUE);
		link = link->next;
	}
	return (FALSE);
}

static t_room   *find_room(t_list *room, char *name)
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

static t_bool   add_links(t_list **room, char *line)
{
	char    **split;
	t_room  *room1;
	t_room  *room2;
	t_bool  ret;

	ret = TRUE;
	split = ft_strsplit(line, '-');
	if (ft_tablen(split) != 2 || ft_strcmp(split[0], split[1]) == 0
			|| (room1 = find_room(*room, split[0])) == NULL
			|| (room2 = find_room(*room, split[1])) == NULL)
		ret = FALSE;
	else
		ft_lstadd(&room1->links, ft_lstnew(room2, 0));
	ft_deltab(split, 0);
	return (ret);
}

t_bool          get_links(t_env *e, char **line)
{
	if (add_links(&e->room,  *line) == FALSE)
		return (FALSE);
	while (get_next_line(0, line) > 0)
	{
		ft_lstadd(&e->anthill, ft_lstnew((void *)*line, 0));
		if (*line[0] != '#' && add_links(&e->room, *line) == FALSE)
			break ;
	}
	return (TRUE);
}
