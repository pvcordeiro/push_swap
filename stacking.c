/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:56:42 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/27 13:24:49 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		quit();
	node->value = value;
	node->next = NULL;
	return (node);
}

void	add_to_stack(t_stack **stack, int value)
{
	t_stack	*node;

	node = new_node(value);
	node->next = *stack;
	*stack = node;
}

int	init_stack(int argc, char **argv, t_stack **stack)
{
	int	i;
	int	value;

	i = argc - 1;
	while (i > 0)
	{
		value = ft_atoi(argv[i]);
		// if (!value)
		// 	return (0);
		add_to_stack(stack, value);
		i--;
	}
	return (1);
}

void	free_and_quit(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
