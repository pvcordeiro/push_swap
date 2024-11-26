/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_prep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:15:41 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/26 18:28:38 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calculate_ranks(t_stack *stack, int *ranks)
{
	t_stack	*temp1;
	t_stack	*temp2;
	int		i;
	int		rank;

	temp1 = stack;
	i = 0;
	while (temp1)
	{
		rank = 0;
		temp2 = stack;
		while (temp2)
		{
			if (temp2->value < temp1->value)
				rank++;
			temp2 = temp2->next;
		}
		ranks[i] = rank;
		i++;
		temp1 = temp1->next;
	}
}

static void	update_stack_with_ranks(t_stack *stack, int *ranks)
{
	t_stack	*temp1;
	int		j;

	temp1 = stack;
	j = 0;
	while (temp1)
	{
		temp1->value = ranks[j];
		j++;
		temp1 = temp1->next;
	}
}

void	normalize_stack(t_stack *stack)
{
	int	*ranks;
	int	size;

	size = stack_size(stack);
	ranks = ft_calloc(size, sizeof(int));
	calculate_ranks(stack, ranks);
	update_stack_with_ranks(stack, ranks);
	free(ranks);
}
