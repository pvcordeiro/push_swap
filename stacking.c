/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:56:42 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/27 20:33:13 by paude-so         ###   ########.fr       */
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
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
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
	return ((int)(result * sign));
}

static t_stack	*new_node(int nb)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		quit();
	node->number = nb;
	node->next = NULL;
	return (node);
}

int	init_stack(char **argv, t_stack **stack)
{
	int		nb;
	t_stack	*tmp;
	t_stack	*end;

	while (*argv)
	{
		nb = ft_atoi(argv);
		if (**argv && **argv != ' ')
			return (0);
		tmp = new_node(nb);
		if (!*stack)
			*stack = tmp;
		else
			end->next = tmp;
		end = tmp;
		argv += (**argv == 0);
	}
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
