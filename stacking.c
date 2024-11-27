/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:56:42 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/27 18:15:50 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		quit();
	node->value = value;
	node->next = NULL;
	return (node);
}

int	init_stack(char **argv, t_stack **stack)
{
	int		value;
	t_stack	*tmp;
	t_stack	*end;

	while (*argv)
	{
		value = ft_atoi(argv);
		if (**argv && **argv != ' ')
			return (0);
		tmp = new_node(value);
		if (*stack == NULL)
			*stack = tmp;
		else
			end->next = tmp;
		end = tmp;
		argv += (**argv == 0);
	}
	return (1);
}
