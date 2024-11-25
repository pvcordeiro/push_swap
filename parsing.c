/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:05:04 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/25 11:56:45 by paude-so         ###   ########.fr       */
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
	char	**tmp;
	
	if (!matrix)
		return ;
	tmp = matrix;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(matrix);
}

static int	fill_stack(t_stack *stack, char **numbers, int free_needed)
{
	t_node	*new_node;

	while (*numbers)
	{
		new_node = create_node(*numbers, stack, numbers, free_needed);
		if (!add_node_to_stack(stack, new_node, numbers, free_needed))
			return (0);
		numbers++;
	}
	if (free_needed)
		free_matrix(numbers - stack->size);
	return (1);
}

static int	add_node_to_stack(t_stack *stack, t_node *node, char **numbers, int free_needed)
{
	if (!node)
		return (0);
	node->next = stack->top;
	stack->top = node;
	stack->size++;
	return (1);
}

static t_node	*create_node(char *value, t_stack *stack, char **numbers, int free_needed)
{
	t_node	*new_node;

	if (!is_number(value))
	{
		free_stack(stack);
		if (free_needed)
			free_matrix(numbers);
		return (NULL);
	}
	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		free_stack(stack);
		if (free_needed)
			free_matrix(numbers);
		return (NULL);
	}
	new_node->value = ft_atoi(value);
	new_node->next = NULL;
	return (new_node);
}