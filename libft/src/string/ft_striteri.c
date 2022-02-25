/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:45:38 by mmeising          #+#    #+#             */
/*   Updated: 2021/10/27 22:53:15 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Applies the function f to each character of the string passed as argument,
 *	and passing its index as first argument. Each character is passed by address
 *	to f to be modified if necessary
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			f(i, &s[i]);
			i++;
		}
	}
}
