/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_entry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:24:46 by marvin            #+#    #+#             */
/*   Updated: 2018/11/08 18:04:20 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

t_bool	parser_entry(t_env *e)
{
	char *line;

	if (get_ants(e, &line) == FALSE)
		return (FALSE);
	if (get_rooms(e, &line) == FALSE)
		return (FALSE);
	if (get_links(e, &line) == FALSE)
		return (FALSE);
	if (get_runs(e, &line) == FALSE)
		return (FALSE);
	ft_lstrev(&e->runs);
	ft_lstrev(&e->anthill);
	return (TRUE);
}
