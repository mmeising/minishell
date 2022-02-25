/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 21:02:07 by mmeising          #+#    #+#             */
/*   Updated: 2021/10/27 21:09:57 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_for_malloc(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	if (nb == 0)
		count++;
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

/*
 *	takes input integer n and returns (malloc'd) string representation of it
 */
char	*ft_itoa(int n)
{
	char	*string;
	int		count;
	long	nb;

	nb = n;
	count = ft_count_for_malloc(nb);
	string = (char *)malloc(sizeof(char) * (count + 1));
	if (!string)
		return (NULL);
	string[count--] = '\0';
	if (nb == 0)
		string[0] = '0';
	if (nb == 0)
		return (string);
	if (nb < 0)
		string[0] = '-';
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		string[count] = '0' + (nb % 10);
		nb = nb / 10;
		count--;
	}
	return (string);
}
