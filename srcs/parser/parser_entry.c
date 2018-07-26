/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_entry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:24:46 by marvin            #+#    #+#             */
/*   Updated: 2018/07/26 20:34:08 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

t_bool  parser_entry(t_env *e)
{
	char *line;

	if (get_ants(e, &line) == FALSE)
		return (FALSE);
	if (get_rooms(e, &line) == FALSE)
		return (FALSE);
	if (get_links(e, &line) == FALSE)
		return (FALSE);
    return (TRUE);
}
