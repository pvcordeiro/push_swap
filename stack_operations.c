/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:36:00 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/22 20:10:14 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dest, char name)
{
	t_node	*temp;

	if (!src->top)
		return ;
	temp = src->top;
	src->top = src->top->next;
	temp->next = dest->top;
	dest-top = next;
	src->size--;
	dest->size++;
	if (name == 'a')
		write (1, "pa", 2);
	else
		write (1, "pb", 2);
}

void	swap(t_stack *stack, char name)
{
	t_node	*first;
	t_node	*second;

	if (!stack->top || stack->top->next)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	if (name == 'a')
		write(1, "sa", 2);
	else
		write (1, "sb", 2);
}

void	rotate(t_stack *stack, char name)
{
	t_node	*temp;
	t_node	*last;

	if (!stack->top || !stack->top->next)
		return ;
	temp = stack->top;
	stack->top = stack->top->next;
	temp->next = NULL;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = temp;
	if (name == 'a')
		write(1, "ra", 2);
	else
		write(1, "ra", 2);
}

void	reverse_rotate(t_stack *stack, char name)
{
	t_node	*prev;
	t_node	*last;

	if (!stack->top || !stack->top->next)
		return ;
	prev = NULL;
	last = stack->top;
	while(last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
	if (name = 'a')
		write (1, "rra", 3);
	else
		write (1, "rrb", 3);
}
