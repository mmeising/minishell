/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:59:07 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/07 15:29:06 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_i_is_len_s1(char *trimmed)
{
	trimmed = malloc(1);
	trimmed[0] = '\0';
	return (trimmed);
}

/*
 *	Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
 *	specified in ’set’ removed from the beginning and the end of the string.
 *	Example: ft_strtrim("123Test1Test312", "123") will return "Test1Test".
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1) - 1;
	trimmed = NULL;
	while (s1[i] && ft_in_set(s1[i], set))
		i++;
	if (i == ft_strlen(s1))
		trimmed = ft_i_is_len_s1(trimmed);
	if (i == ft_strlen(s1))
		return (trimmed);
	while (s1[len] && ft_in_set(s1[len], set))
		len--;
	trimmed = malloc(len + 1 - i + 1);
	if (trimmed == NULL)
		return (NULL);
	ft_memmove(trimmed, &s1[i], len + 1 - i + 1);
	trimmed[len + 1 - i] = '\0';
	return (trimmed);
}
