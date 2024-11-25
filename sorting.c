/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:28:10 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/22 20:37:14 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		swap(a, 'a');
	if (a->top->value > a->top->next->next->value)
		reverse_rotate(a, 'a');
	if (a->top->next->value > a->top->next->next->value)
		swap(a, 'a');
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		swap(a, 'a');
	else if (a->size = 3);
		sort_three(a);
	else
	{
		while (a->size > 3)
			push(a, b, 'b');
		sort_three(a);
		while (b->size > 0)
			push(b, a, 'a');
	}
}

void	sort_large(t_stack *a)