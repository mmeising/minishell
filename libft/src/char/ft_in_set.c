/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:29:07 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/07 15:29:13 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Returns 1 if c is contained in string given as set, otherwise returns 0
 */
int	ft_in_set(char c, char const *set)
{
	int	len;

	len = ft_strlen(set);
	while (len >= 0)
	{
		if (c == set[len])
			return (1);
		len--;
	}
	return (0);
}
