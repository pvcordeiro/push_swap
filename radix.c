/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:22:57 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/26 16:35:50 by paude-so         ###   ########.fr       */
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

void radix(t_stack **a, t_stack **b)
{
    int max_bits = find_max_bits(*a);
    for (int bit = 0; bit < max_bits; bit++)
    {
        int size = stack_size(*a);
        for (int i = 0; i < size; i++)
        {
            if (((*a)->value >> bit) & 1)
                ra(a);
            else
                pb(a, b);
        }
        while (*b)
            pa(a, b);
    }
}
