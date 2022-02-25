/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:16:45 by mmeising          #+#    #+#             */
/*   Updated: 2021/10/27 22:32:10 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_end_part(unsigned char *psrc, unsigned char *pdst, unsigned int len)
{
	while (len > 0)
	{
		pdst[len - 1] = psrc[len - 1];
		len--;
	}
}

/*
 *	copies n bytes from memory area of src to memory area of dst
 */
void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	unsigned char	*ptr_src;
	unsigned char	*ptr_dst;

	ptr_src = (unsigned char *)src;
	ptr_dst = (unsigned char *)dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (src > dst)
	{
		while (len > 0)
		{
			*ptr_dst = *ptr_src;
			ptr_dst++;
			ptr_src++;
			len--;
		}
	}
	else
		ft_end_part(ptr_src, ptr_dst, len);
	return (dst);
}
