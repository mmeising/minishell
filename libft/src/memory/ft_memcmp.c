/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:36:13 by mmeising          #+#    #+#             */
/*   Updated: 2021/10/27 21:15:23 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	compares n bytes long strings s1 and s2, returns 0 if identical,
 *	else returns difference between first two differing bytes
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;
	size_t			i;

	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (ptr_s1[i] == ptr_s2[i] && i < n - 1)
		i++;
	if (ptr_s1[i] == ptr_s2[i])
		return (0);
	else
		return (ptr_s1[i] - ptr_s2[i]);
}
