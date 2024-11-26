/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:59:12 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/26 15:53:21 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char	**argv)
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
	
	argv = ft_split(argv[1], ' ');
	if (!argv)
	{
		free_split(argv);
		quit();
	}
	temp = argv;
	while (*temp)
		temp++;
	init_stack(temp - argv + 1, argv - 1, a);
	free_split(argv);
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

static void normalize_stack(t_stack *stack)
{
    t_stack *temp1;
    t_stack *temp2;
    int     rank;

    temp1 = stack;
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
        temp1->value = rank;
        temp1 = temp1->next;
    }
}

int	handle_stack(int argc, char **argv, t_stack **a, t_stack **b)
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
	else if (stack_size(*a) <= 6)
		sort_six(a, b);
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
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	if (!handle_stack(argc, argv, &a, &b))
		return (0);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
