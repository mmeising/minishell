/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:09:59 by mmeising          #+#    #+#             */
/*   Updated: 2021/10/27 20:59:38 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	mallocs an array, sets bytes to \0 and returns the array
 */
void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned int	i;

	i = (count * size);
	ptr = malloc(i);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
