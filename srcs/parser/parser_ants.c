/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 20:18:11 by rpinoit           #+#    #+#             */
/*   Updated: 2018/07/26 20:34:59 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

t_bool  get_ants(t_env *e, char **line)
{
	if (get_next_line(0, line) != 1)
		return (FALSE);
	while (*line[0] == '#')
	{
		ft_lstadd(&e->anthill, ft_lstnew((void *)*line, 0));
		if (get_next_line(0, line) != 1)
			return (FALSE);
	}
	if (ft_isstrint(*line, &e->ants) == FALSE || e->ants < 0)
	{
		ft_strdel(&(*line));
		return (FALSE);
	}
	ft_lstadd(&e->anthill, ft_lstnew((void *)*line, 0));
	return (TRUE);
}
