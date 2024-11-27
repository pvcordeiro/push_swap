/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:17:18 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/27 21:16:23 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_stack_operations(t_stack **a, t_stack **b, int size)
{
	int	half;

	half = size / 2;
	while (half--)
		pb(a, b);
}

static void	merge_sorted_stacks(t_stack **a, t_stack **b, int left_size,
		int right_size)
{
	int	total_size;

	total_size = left_size + right_size;
	while (left_size > 0 && right_size > 0)
	{
		if ((*b)->number < (*a)->number)
		{
			pa(a, b);
			right_size--;
		}
		else
		{
			ra(a);
			left_size--;
		}
	}
	while (right_size--)
		pa(a, b);
	while (total_size--)
		rra(a);
}

static void	merge_sort_operations(t_stack **a, t_stack **b, int size)
{
	int	left_size;
	int	right_size;

	if (size <= 1)
		return ;
	left_size = size / 2;
	right_size = size - left_size;
	split_stack_operations(a, b, size);
	merge_sort_operations(a, b, left_size);
	merge_sort_operations(b, a, right_size);
	merge_sorted_stacks(a, b, left_size, right_size);
}

void	merge_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(a);
	if (size <= 1)
		return ;
	merge_sort_operations(a, b, size);
}
