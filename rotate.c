/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:14:01 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/28 11:31:30 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*new_tail;
	t_stack	*new_head;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	new_tail = *stack;
	*stack = new_tail->next;
	new_tail->next = NULL;
	new_head = *stack;
	while (new_head->next)
		new_head = new_head->next;
	new_head->next = new_tail;
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
