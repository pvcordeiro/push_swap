/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:22:57 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/26 14:25:27 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	size;
	t_stack *temp;

	size = 0;
	temp = stack;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

static int	find_max_bits(t_stack *stack)
{
	int		max;
	int		bits;
	t_stack *temp;

	max = 0;
	bits = 0;
	temp = stack;
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix(t_stack **a, t_stack **b)
{
	int	max_bits;
	int	bit;
	int	size;
	int	value;

	max_bits = find_max_bits(*a);
	bit = 0;
	while (bit < max_bits)
	{
		size = stack_size(*a);
		while (size > 0)
		{
			value = (*a)->value;
			if (((value >> bit) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			size--;
		}
		while (*b)
			pa(a, b);
		bit++;
	}
}