/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:27:15 by mmeising          #+#    #+#             */
/*   Updated: 2021/10/27 23:27:17 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Locates the last occurence of c (converted to a char) in the string pointed
 *	to by str.
 */
char	*ft_strrchr(const char *str, int c)
{
	int			i;
	const char	*ptr;

	ptr = 0;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == c)
		{
			ptr = &str[i];
			return ((char *)ptr);
		}
		i--;
	}
	return ((char *)ptr);
}
