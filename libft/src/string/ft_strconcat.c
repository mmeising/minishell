/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 23:10:56 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/05 17:25:01 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_concatenate(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = '\0';
	return (ret);
}

/*
 *	Usage:
 *	s1 = ft_strconcat(&s1, &s2);
 *	Allocates (with malloc(3)) and returns a new NULL-terminated string, 
 *	which is the result of the concatenation of 's1' and 's2'.
 *	s1 and s2 are passed as address of string.
 *	Original s1 and s2 are freed afterwards
 */
char	*ft_strcon(char **s1, char **s2)
{
	char	*ret;

	if (*s1 && *s2)
	{
		ret = ft_concatenate(*s1, *s2);
		ft_free_c(s1);
		ft_free_c(s2);
		return (ret);
	}
	return (NULL);
}
