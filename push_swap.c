/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:59:12 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/27 18:16:46 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_and_quit(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	sort_stack(t_stack **a, t_stack **b)
{
	if (stack_size(*a) == 2 && !is_sorted(*a))
		sa(a);
	else if (stack_size(*a) <= 10)
		sort_ten(a, b);
	// else if (stack_size(*a) <= 100)
	// 	merge_sort(a, b);
	else
		radix(a, b);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (!argv[1][0] || argv[1][0] == ' ')
		quit();
	if ((argv[1][0] == '-' && !argv[1][1]) || argv[1][0] == '+')
		quit();
	if (!init_stack(++argv, &a))
		free_and_quit(&a);
	if (!check_duplicates(&a))
		free_and_quit(&a);
	if (is_sorted(a))
		return (free_stack(&a), 0);
	sort_stack(&a, &b);
	free_stack(&a);
	return (0);
}
