/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:56:42 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/29 20:50:25 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoi(char **str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	if (**str == '-')
		sign = -sign;
	*str += (**str == '-' || **str == '+');
	**str = (**str * (**str >= '0' && **str <= '9')) + \
	!(**str >= '0' && **str <= '9');
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10 + (**str - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
		{
			**str = 'e';
			return (0);
		}
		(*str)++;
	}
	return ((result * sign));
}

static t_stack	*create_node(int nb)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		exit(EXIT_FAILURE);
	node->number = nb;
	node->next = NULL;
	return (node);
}

int	init_stack(char **argv, t_stack **stack)
{
	int		nb;
	t_stack	*new_node;
	t_stack	*last_node;

	while (*argv)
	{
		nb = ft_atoi(argv);
		if (**argv && **argv != ' ')
			return (0);
		new_node = create_node(nb);
		if (!*stack)
			*stack = new_node;
		else
			last_node->next = new_node;
		last_node = new_node;
		if (!**argv)
			argv++;
	}
	return (1);
}

int	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	return (0);
}

