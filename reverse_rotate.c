/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:24:00 by paude-so          #+#    #+#             */
/*   Updated: 2024/12/02 11:28:20 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*new_tail;
	t_stack	*old_tail;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	new_tail = *stack;
	while (new_tail->next->next)
		new_tail = new_tail->next;
	old_tail = new_tail->next;
	new_tail->next = NULL;
	old_tail->next = *stack;
	*stack = old_tail;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
