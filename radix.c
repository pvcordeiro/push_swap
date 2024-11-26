/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:22:57 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/26 17:58:11 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int		size;
	t_stack	*temp;

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
	t_stack	*temp;

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

void	normalize_stack(t_stack *stack)
{
	t_stack	*temp1;
	t_stack	*temp2;
	int		*ranks;
	int		i;
	int		j;
	int		size;
	int		rank;

	i = 0;
	size = stack_size(stack);
	ranks = ft_calloc(size, sizeof(int));
	temp1 = stack;
	while (temp1)
	{
		rank = 0;
		temp2 = stack;
		while (temp2)
		{
			if (temp2->value < temp1->value)
				rank++;
			temp2 = temp2->next;
		}
		ranks[i++] = rank;
		temp1 = temp1->next;
	}
	temp1 = stack;
	j = 0;
	while (temp1)
	{
		temp1->value = ranks[j];
		temp1 = temp1->next;
		j++;
	}
	free(ranks);
}

void	radix(t_stack **a, t_stack **b)
{
	int	max_bits;
	int	a_size;
	int	bit;

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
