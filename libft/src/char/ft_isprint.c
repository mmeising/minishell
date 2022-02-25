/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:40:38 by mmeising          #+#    #+#             */
/*   Updated: 2021/10/27 21:03:15 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	returns 1 if c is printable char (ASCII value 32 to 126), else returns 0
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
