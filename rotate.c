/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:14:01 by paude-so          #+#    #+#             */
/*   Updated: 2024/12/02 11:27:02 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*new_tail;
	t_stack	*tail_finder;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	new_tail = *stack;
	*stack = new_tail->next;
	new_tail->next = NULL;
	tail_finder = *stack;
	while (tail_finder->next)
		tail_finder = tail_finder->next;
	tail_finder->next = new_tail;
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
