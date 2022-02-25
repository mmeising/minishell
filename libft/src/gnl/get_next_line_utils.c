/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 20:59:36 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/05 00:00:46 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 *	frees buf[fd] and ret in case read fails (error or no new content)
 */
void	*ft_read_fail(char **buf, int fd, char *ret)
{
	free(buf[fd]);
	buf[fd] = NULL;
	free(ret);
	ret = NULL;
	return (NULL);
}
