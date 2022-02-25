/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:41:22 by mmeising          #+#    #+#             */
/*   Updated: 2021/07/14 20:20:58 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ele;

	ele = (t_list *)malloc(sizeof(*ele));
	if (ele == NULL)
		return (NULL);
	ele->content = content;
	ele->next = NULL;
	return (ele);
}
