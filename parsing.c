/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:05:04 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/22 21:10:04 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*initialize_stack(int argc, char **argv)
{
	t_stack *stack;
	char	**numbers;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	if (argc = 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = argv + 1;
	if (!fill_stack(stack, numbers, argc == 2))
		return (NULL);
	return (stack);
}

static int	is_number(char *str)
{
	if (*str == '-' || *str == "+")
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

static void	free_matrix(char **matrix)
{
	if (!matrix)
		return ;
	while (*matrix)
	{
		free(*matrix);
		matrix++;
	}
	free(matrix);
}

static int	fill_stack(t_stack *stack, char **numbers, int free_needed)
{
	t_node	*new_node;
	int		i;

	i = 0;
	while ()
}