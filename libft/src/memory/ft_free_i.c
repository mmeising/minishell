/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:42:27 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/04 23:17:56 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	frees int pointer given as argument and sets it to NULL
 */
void	ft_free_i(int **ptr)
{
	free(*ptr);
	*ptr = NULL;
}
