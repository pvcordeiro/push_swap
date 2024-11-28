/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_prep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:15:41 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/28 12:14:46 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calculate_ranks(t_stack **stack, int *ranks)
{
	t_stack	*tmp;
	t_stack	*cmp_node;
	int		cmp_rank;

	tmp = *stack;
	while (tmp)
	{
		cmp_rank = 0;
		cmp_node = *stack;
		while (cmp_node)
		{
			if (cmp_node->number < tmp->number)
				cmp_rank++;
			cmp_node = cmp_node->next;
		}
		*ranks++ = cmp_rank;
		tmp = tmp->next;
	}
}

static void	update_stack_with_ranks(t_stack **stack, int *ranks)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		tmp->number = *ranks++;
		tmp = tmp->next;
	}
}

void	normalize_stack(t_stack **stack)
{
	int	*ranks;
	int	size;

	size = stack_size(stack);
	ranks = malloc(size * sizeof(int));
	calculate_ranks(stack, ranks);
	update_stack_with_ranks(stack, ranks);
	free(ranks);
}
