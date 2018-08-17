/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 21:26:07 by rpinoit           #+#    #+#             */
/*   Updated: 2018/08/17 10:15:13 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void    del_str(void *content, size_t content_size)
{
	char *tmp;

	(void)content_size;
	tmp = (char *)content;
	ft_strdel(&tmp);
}

void    del_nothing(void *content, size_t content_size)
{
	(void)content;
	(void)content_size;
}

void    del_room(void *content, size_t content_size)
{
	t_room *tmp;

	(void)content_size;
	tmp = (t_room*)content;
	ft_lstdel(&tmp->links, &del_nothing);
	ft_strdel(&tmp->name);
	free(content);
}
