/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:48:46 by mmeising          #+#    #+#             */
/*   Updated: 2021/10/27 23:06:18 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Appends string src to the end of dst.
 *	Appends at most dstsize - strlen(dst) - 1 characters.
 *	NUL-terminates unless dstsize = 0 or the dst is longer than dstsize.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	if (dstsize <= dst_len)
		src_len += dstsize;
	else
		src_len += dst_len;
	while ((dst_len + 1) < dstsize && src[i] != '\0')
	{
		dst[dst_len] = src[i];
		dst_len++;
		i++;
	}
	if (dst_len <= dstsize)
		dst[dst_len] = '\0';
	return (src_len);
}
