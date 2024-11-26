/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:22:57 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/26 18:18:33 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int		size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

static int	find_max_bits(t_stack *stack)
{
	int		max;
	int		bits;

	max = 0;
	bits = 0;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	while (max >> bits)
		bits++;
	return (bits);
}

void	radix(t_stack **a, t_stack **b)
{
	int	max_bits;
	int	a_size;
	int	bit;

	normalize_stack(*a);
	max_bits = find_max_bits(*a);
	bit = 0;
	while (bit < max_bits)
	{
		a_size = stack_size(*a);
		while (a_size--)
		{
			if (((*a)->value >> bit) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (*b)
			pa(a, b);
		bit++;
	}
}
