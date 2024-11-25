/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:36:10 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/25 19:58:47 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_index(t_stack *stack)
{
	int		index;
	int		min_index;
	int		min_value;
	t_stack	*temp;

	index = 0;
	min_index = 0;
	min_value = stack->value;
	temp = stack;
	while (temp)
	{
		if (temp->value < min_value)
		{
			min_value = temp->value;
			min_index = index;
		}
		index++;
		temp = temp->next;
	}
	return (min_index);
}

static void	sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if(first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > second && first > third)
		ra(stack);
	else if (second > third && first < third)
	{
		sa(stack);
		ra(stack);
	}
	else if (first > second)
		sa(stack);
	else if (first < third && second > third)
		rra(stack);
}

void	sort_ten_or_less(t_stack **a, t_stack **b)
{
	int	min_index;

	while (stack_size(*a) > 3)
	{
		min_index = find_min_index(*a);
		while (min_index > 0)
		{
			if (min_index <= stack_size(*a) / 2)
				ra(a);
			else
				rra(a);
			min_index--;
		}
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}
