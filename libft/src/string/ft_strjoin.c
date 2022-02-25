/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:41:40 by mmeising          #+#    #+#             */
/*   Updated: 2021/10/27 23:02:59 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Allocates (with malloc(3)) and returns a new string, which is the result of
 *	the concatenation of 's1' and 's2'
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(len_s1 + len_s2 + 1);
	if (str == (NULL))
		return (NULL);
	ft_memcpy(str, s1, len_s1);
	ft_memcpy((str + len_s1), s2, len_s2);
	str[len_s1 + len_s2] = '\0';
	return (str);
}
