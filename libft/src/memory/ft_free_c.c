/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:27:12 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/04 22:43:39 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	frees char pointer given as argument and sets it to NULL
 */
void	ft_free_c(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}
