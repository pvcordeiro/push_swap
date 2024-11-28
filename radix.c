/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:22:57 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/28 11:32:02 by paude-so         ###   ########.fr       */
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
		if (tmp->number > max)
			max = tmp->number;
		tmp = tmp->next;
	}
	while (max >> bits)
		bits++;
	return (bits);
}

void	radix(t_stack **a, t_stack **b)
{
	int	max_bits;
	int	stack_size_a;
	int	stack_size_b;
	int	bit;

	normalize_stack(a);
	max_bits = find_max_bits(a);
	bit = 0;
	while (bit < max_bits)
	{
		stack_size_a = stack_size(a);
		while (stack_size_a--)
		{
			if (((*a)->number >> bit) & 1)
				ra(a);
			else
				pb(a, b);
		}
		stack_size_b = stack_size(b);
		while (stack_size_b--)
		{
			if (((*b)->number >> bit) & 1)
				pa(a, b);
			else
				rb(b);
		}
		bit++;
	}
	while (*b)
		pa(a, b);
}

void	quit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
