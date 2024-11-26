/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:36:10 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/26 20:28:49 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third && first > third)
		(sa(a), rra(a));
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
		(sa(a), ra(a));
	else if (first < second && second > third && first > third)
		rra(a);
	// else if (first < second && second > third && first < third)
	// 	(rra(a), sa(a));
}

static int	find_min_index(t_stack *stack)
{
	int	index;
	int	min_index;
	int	min_value;

	index = 0;
	min_index = 0;
	min_value = stack->value;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_index = index;
		}
		index++;
		stack = stack->next;
	}
	return (min_index);
}

void	sort_ten(t_stack **a, t_stack **b)
{
	int	min_index;

	while (stack_size(*a) > 3)
	{
		min_index = find_min_index(*a);
		if (min_index <= stack_size(*a) / 2)
		{
			while (min_index--)
				ra(a);
		}
		else
		{
			while (min_index++ < stack_size(*a))
				rra(a);
		}
		pb(a, b);
	}
	if (!is_sorted(*a))
		sort_three(a);
	while (*b)
		pa(a, b);
}
