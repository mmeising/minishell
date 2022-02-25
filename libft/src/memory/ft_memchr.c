/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:52:05 by mmeising          #+#    #+#             */
/*   Updated: 2021/10/27 21:12:03 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	searches for c in first n bytes of array str, returns address of it if found
 */
void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ptr_str;
	size_t			i;

	ptr_str = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (ptr_str[i] == (unsigned char)c)
			return (&ptr_str[i]);
		i++;
	}
	return (NULL);
}
