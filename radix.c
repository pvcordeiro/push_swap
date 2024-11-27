/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:22:57 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/27 18:45:42 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack **stack)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

static int	find_max_bits(t_stack **stack)
{
	int		max;
	int		bits;
	t_stack	*tmp;

	max = 0;
	bits = 0;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
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

	normalize_stack(a);
	max_bits = find_max_bits(a);
	bit = 0;
	while (bit < max_bits)
	{
		a_size = stack_size(a);
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
