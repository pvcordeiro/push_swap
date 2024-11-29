/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:36:10 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/29 19:06:37 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->number;
	second = (*a)->next->number;
	third = (*a)->next->next->number;
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
}

static int	find_min_index(t_stack **stack)
{
	int		i;
	int		min_i;
	int		min_value;
	t_stack	*tmp;

	tmp = *stack;
	min_value = tmp->number;
	i = 0;
	min_i = 0;
	while (tmp)
	{
		if (tmp->number < min_value)
		{
			min_value = tmp->number;
			min_i = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (min_i);
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	min_i;
	int	size;

	size = stack_size(a);
	while (size > 3)
	{
		min_i = find_min_index(a);
		if (min_i <= size / 2)
		{
			while (min_i--)
				ra(a);
		}
		else
		{
			while (min_i++ < size)
				rra(a);
		}
		pb(a, b);
		size--;
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}
