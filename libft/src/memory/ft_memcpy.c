/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:29:49 by mmeising          #+#    #+#             */
/*   Updated: 2021/10/27 22:31:46 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	copies n bytes from memory area of src to memory area of dst
 *	if they overlap, behaviour is undefined (use memmove instead)
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	i;
	unsigned char	*ptr_src;
	unsigned char	*ptr_ds;

	i = 0;
	ptr_src = (unsigned char *)src;
	ptr_ds = (unsigned char *)dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		ptr_ds[i] = ptr_src[i];
		i++;
	}
	return (dst);
}
