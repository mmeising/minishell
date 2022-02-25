/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:03:54 by mmeising          #+#    #+#             */
/*   Updated: 2022/02/25 17:04:12 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*new_node(char *value, int type)
{
	t_node		*node;
	static int 	i = 1;

	node = malloc(sizeof(*node));
	if (!node)
		return (0);
	node->value = value;
	node->next = NULL;
	node->index = i;
	i++;
	return (node);
}

t_node	*last_node(t_node *node)
{
	t_node	*first_node;

	if (!node)
		return (NULL);
	first_node = node;
	while (first_node->next)
		first_node = first_node->next;
	return (first_node);
}

void	stack_add_front(t_node *node, t_node *new_start_node)
{
	t_node	*old_first_node;

	old_first_node = new_node(*stack, (*stack)->node->value, 0, c);
	old_first_node->next = (*stack)->node->next;
	(*stack)->node = new_start_node;
	new_start_node->next = old_first_node;
	index_reording(*stack);
}

void	stack_add_back(t_stack **stack, t_node *new_end_node)
{
	t_node	*old_last_node;

	if (!new_end_node)
		return ;
	if ((*stack)->size == 1)
	{
		(*stack)-> node = new_end_node;
		return ;
	}
	old_last_node = last_node(*stack);
	old_last_node->next = new_end_node;
}
