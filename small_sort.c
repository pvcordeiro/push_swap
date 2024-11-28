/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:36:10 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/28 12:42:01 by paude-so         ###   ########.fr       */
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

 

void	sort_ten(t_stack **a, t_stack **b)
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
