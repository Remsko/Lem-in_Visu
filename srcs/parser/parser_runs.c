/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_runs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 13:02:54 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/06 17:51:22 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

/*
** Blank line or parsing error break the last read
*/

t_ant	*get_ant(t_list *ant_tmp, char *split)
{
	t_ant *ant;

	ant = NULL;
	(void)split;
	return (ant);
}

t_list	*get_antlist(t_list *ant_tmp, char *line)
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
		if ((new_ant = get_ant(ant_tmp, split[i])) == NULL)
			return (NULL)
		ft_lstadd(&ant_list, ft_lstnew((void *)new_ant, 0));
		i++;
	}
	ft_deltab(split);
	return (ant_list);
}

t_bool  get_runs(t_env *e, char **line)
{
	t_list *ant_lst;
	t_list *ant_tmp;

	ant_lst = NULL;
	ant_tmp = NULL;
	while (get_next_line(0, line) > 0)
	{
		ft_lstadd(&e->anthill, ft_lstnew((void *)*line, 0));
		if ((ant_lst = get_antlist(ant_tmp, *line)) == NULL)
			return (FALSE);
		ft_lstadd(&e->runs, ft_lstnew((void *)ant_lst, 0));
		ant_tmp = ant_lst;
	}
	return (TRUE);
}