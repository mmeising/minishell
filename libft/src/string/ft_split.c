/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:30:02 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/04 19:38:49 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ele_count(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	*ft_set_headntail(char const *s, char c, size_t headntail[2])
{
	headntail[0] = headntail[1];
	while (s[headntail[0]] == c)
		headntail[0]++;
	headntail[1] = headntail[0];
	while (s[headntail[1]] != c && s[headntail[1]] != '\0')
		headntail[1]++;
	return (headntail);
}

/*
 *	uses ft_substr to allocate and assign the individual strings,
 *	in case of malloc fail it frees all strings and split itself
 */
static size_t	ft_do_strings(char const *s, char c,
				size_t headntail[2], char **split)
{
	int	i;

	i = 0;
	while (i < ft_ele_count(s, c))
	{
		ft_set_headntail(s, c, headntail);
		split[i] = ft_substr(s, headntail[0], headntail[1] - headntail[0] + 1);
		if (split[i] == NULL)
		{
			while (i >= 0)
				free(split[i--]);
			free(split);
			return (0);
		}
		split[i][headntail[1] - headntail[0]] = '\0';
		headntail[0] = headntail[1];
		i++;
	}
	return (i);
}

/*
 *	Allocates (with malloc(3)) and returns an array of strings obtained by
 *	splitting ’s’ using the character ’c’ as a delimiter.
 *	The array must be ended by a NULL pointer.
 */
char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	headntail[2];
	int		test;

	if (!s)
		return (NULL);
	headntail[0] = 0;
	headntail[1] = 0;
	split = (char **)malloc((ft_ele_count(s, c) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	test = ft_do_strings(s, c, headntail, split);
	split[test] = NULL;
	return (split);
}
