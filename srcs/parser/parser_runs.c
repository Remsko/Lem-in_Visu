/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_runs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 13:02:54 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/09 13:55:12 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

t_ant	*get_ant(t_list *room, t_list *prev, char *split)
{
	t_ant *ant;
	t_ant *same;

	if ((ant = (t_ant *)malloc(sizeof(t_ant))) == NULL)
		return (NULL);
	ant->nb = ft_atoi(split + 1);
	same = find_prev(prev, ant);
	ant->prev = same != NULL ? same->next : find_start(room);
	ant->next = find_room(room, ft_strchr(split, '-') + 1);
	if (ant->prev == NULL || ant->next == NULL)
	{
		ft_putendl(split);
		ft_memdel((void**)&ant);
		return (NULL);
	}
	ant->color = same != NULL
		? same->color
		: (t_color){rand() % 255, rand() % 255, rand() % 255};
	return (ant);
}

t_list	*get_antlist(t_list *room, t_list *prev, char *line)
{
	t_list	*ant_list;
	t_ant	*new_ant;
	char	**split;
	int		i;

	i = 0;
	ant_list = NULL;
	if ((split = ft_strsplit(line, ' ')) == NULL)
		return (NULL);
	while (split[i] != NULL)
	{
		if ((new_ant = get_ant(room, prev, split[i])) == NULL)
		{
			ft_deltab(split, 0);
			return (NULL);
		}
		ft_lstadd(&ant_list, ft_lstnew((void *)new_ant, 0));
		i++;
	}
	ft_deltab(split, 0);
	return (ant_list);
}

t_bool	get_runs(t_env *e, char **line)
{
	t_list *ant_list;
	t_list *prev_list;

	ant_list = NULL;
	prev_list = NULL;
	while (get_next_line(0, line) > 0)
	{
		ft_lstadd(&e->anthill, ft_lstnew((void *)*line, 0));
		if ((ant_list = get_antlist(e->room, prev_list, *line)) == NULL)
			return (FALSE);
		ft_lstadd(&e->runs, ft_lstnew((void *)ant_list, 0));
		prev_list = ant_list;
	}
	return (TRUE);
}
