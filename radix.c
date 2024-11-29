/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:22:57 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/29 20:57:20 by paude-so         ###   ########.fr       */
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

static void	normalize_stack(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*cmp_node;

	tmp = *a;
	while (tmp)
	{
		tmp->rank = 0;
		cmp_node = *a;
		while (cmp_node)
		{
			tmp->rank += (cmp_node->number < tmp->number);
			cmp_node = cmp_node->next;
		}
		tmp = tmp->next;
	}
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
		if (tmp->rank > max)
			max = tmp->rank;
		tmp = tmp->next;
	}
	while (max >> bits)
		bits++;
	return (bits);
}

static void	process_stacks(t_stack **a, t_stack **b, int bit)
{
	int	a_size;
	int	b_size;

	a_size = stack_size(a);
	while (a_size--)
	{
		if (((*a)->rank >> bit) & 1)
			ra(a);
		else
			pb(a, b);
	}
	b_size = stack_size(b);
	while (b_size--)
	{
		if (((*b)->rank >> bit) & 1)
			pa(a, b);
		else
			rb(b);
	}
}

void	radix(t_stack **a, t_stack **b)
{
	int	max_bits;
	int	bit;

	normalize_stack(a);
	max_bits = find_max_bits(a);
	bit = 0;
	while (bit < max_bits)
		process_stacks(a, b, bit++);
	while (*b)
		pa(a, b);
}
