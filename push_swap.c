/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:59:12 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/29 20:50:30 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_and_quit(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static int	check_duplicates(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = *stack;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->number == tmp2->number)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

static int	is_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->number > tmp->next->number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	sort_stack(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (stack_size(a) == 2 && !is_sorted(a))
		sa(a);
	else if (stack_size(a) <= 70)
		sort_small(a, &b);
	else
		radix(a, &b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	if (argc == 1)
		return (0);
	if (!init_stack(++argv, &a))
		free_and_quit(&a);
	if (!check_duplicates(&a))
		free_and_quit(&a);
	if (is_sorted(&a))
		return (free_stack(&a));
	sort_stack(&a);
	free_stack(&a);
	return (0);
}
