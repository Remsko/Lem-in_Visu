/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 20:28:04 by rpinoit           #+#    #+#             */
/*   Updated: 2018/07/26 21:45:32 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static t_room_type  get_room_type(char *line)
{
	if (ft_strcmp(line, "##start") == 0)
		return (START);
	else if (ft_strcmp(line, "##end") == 0)
		return (END);
	return (BASIC);
}

static t_bool       same_room(t_list *room, t_room *new)
{
	t_room *tmp;

	if (new == NULL)
		return (TRUE);
	while (room != NULL)
	{
		tmp = (t_room *)room->content;
		if (ft_strcmp(new->name, tmp->name) == 0)
			return (TRUE);
		else if (new->pos.x == tmp->pos.x && new->pos.y == tmp->pos.y)
			return (TRUE);
		else if (new->type != BASIC && new->type == tmp->type)
			return (TRUE);
		room = room->next;
	}
	return (FALSE);
}

static t_room       init_room(char *split, t_coord pos, t_room_type type)
{
	t_room room;

	room.name = ft_strdup(split);
	room.pos = pos;
	room.type = type;
	return (room);
}

static t_bool       add_room(t_env *e, char *line, t_room_type type)
{
	t_room  *new;
	char    **split;
	t_coord pos;
	t_bool  ret;

	new = NULL;
	ret = TRUE;
	split = ft_strsplit(line, ' ');
	if (line[0] == 'L' || ft_tablen(split) != 3
			|| ft_isstrint(split[1], &pos.x) == FALSE
			|| ft_isstrint(split[2], &pos.y) == FALSE)
		ret = FALSE;
	else if ((new = (t_room *)malloc(sizeof(t_room))) == NULL)
		ret = FALSE;
	else
		*new = init_room(split[0], pos, type);
	if (same_room(e->room, new) == TRUE)
	{
		new == NULL ? 0 : del_room((void*)new, 0);
		ret = FALSE;
	}
	else
		ft_lstadd(&e->room, ft_lstnew((void *)new, 0));
	ft_deltab(split, 0);
	return (ret);
}

t_bool              get_rooms(t_env *e, char **line)
{
	t_room_type type;
	int         mark;

	type = BASIC;
	mark = 0;
	while (get_next_line(0, line) > 0)
	{
		ft_lstadd(&e->anthill, ft_lstnew((void *)*line, 0));
		if (*line[0] == '#')
			type = get_room_type(*line);
		else if (add_room(e, *line, type) == TRUE)
		{
			if (type != BASIC)
				mark += (int)type;
			type = BASIC;
		}
		else
			break ;
	}
	if (mark != (int)(START + END))
		return (FALSE);
	ft_lstrev(&e->room);
	return (TRUE);
}
