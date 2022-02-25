/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:29:27 by mmeising          #+#    #+#             */
/*   Updated: 2021/10/27 21:03:24 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	returns 1 if c is a standard ASCII character (0-127), else returns 0
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
