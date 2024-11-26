/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:59:12 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/26 17:51:52 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_matrix(char **argv)
{
	char	**start;

	start = argv;
	while (*argv)
		free(*argv++);
	free(start);
}

static void	single_string(char **argv, t_stack **a)
{
	char	**temp;

	argv = split(argv[1]);
	if (!argv)
	{
		free_stack(a);
		quit();
	}
	temp = argv;
	while (*temp)
		temp++;
	init_stack(temp - argv + 1, argv - 1, a);
	free_matrix(argv);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	handle_stack(int argc, char **argv, t_stack **a, t_stack **b)
{
	if (argc == 2)
		single_string(argv, a);
	else
		init_stack(argc, argv, a);
	check_duplicates(*a);
	if (is_sorted(*a))
		return (free_stack(a), 0);
	else if (stack_size(*a) == 2 && !is_sorted(*a))
		sa(a);
	else if (stack_size(*a) <= 10)
		sort_ten(a, b);
	else
	{
		normalize_stack(*a);
		radix(a, b);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || !argv[1][0])
		quit();
	if (!handle_stack(argc, argv, &a, &b))
		return (0);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
