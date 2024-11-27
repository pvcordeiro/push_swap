/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:17:18 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/27 12:24:24 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void split_stack_operations(t_stack **a, t_stack **b, int size)
{
    int i;

	i = 0;
    while (i < size / 2)
    {
        pb(a, b);
        i++;
    }
}

static void merge_sorted_stacks(t_stack **a, t_stack **b, int left_size, int right_size)
{
    int total_size;
	
	total_size = left_size + right_size;
    while (left_size > 0 && right_size > 0)
    {
        if ((*b)->value < (*a)->value)
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
    while (right_size-- > 0)
        pa(a, b);
    while (total_size-- > 0)
        rra(a);
}

static void merge_sort_operations(t_stack **a, t_stack **b, int size)
{
    if (size <= 1)
        return;
    int left_size = size / 2;
    int right_size = size - left_size;
    split_stack_operations(a, b, size);
    merge_sort_operations(a, b, left_size);
    merge_sort_operations(b, a, right_size);
    merge_sorted_stacks(a, b, left_size, right_size);
}

void merge_sort(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);

	size = stack_size(*a);
    if (size <= 1)
        return;
    merge_sort_operations(a, b, size);
}
