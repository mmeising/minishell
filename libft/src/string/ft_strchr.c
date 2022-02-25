/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 19:10:35 by mmeising          #+#    #+#             */
/*   Updated: 2021/10/27 22:47:27 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Locates the first occurence of c (converted to char) in the string pointed
 *	to by s. Terminating null byte is considered to be part of the string;
 *	therefore if c is '\0', the function locates the terminating '\0'
 */
char	*ft_strchr(const char *str, int c)
{
	int			i;
	const char	*ptr;

	ptr = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			ptr = &str[i];
			return ((char *)ptr);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		ptr = &str[i];
		return ((char *)ptr);
	}
	return (NULL);
}
