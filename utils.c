/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:24:54 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/26 14:18:02 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_null(t_stack **stack)
{
	return (!(*stack) || !(*stack)->next);
}

int	ft_atoi(const char *str)
{
	long	result = 0;
	int		sign = 1;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			quit();
		str++;
	}
	if (*str != '\0')
		quit();
	return (int)(result *sign);
}

void	check_duplicates(t_stack *stack)
{
	t_stack	*outer;
	t_stack	*inner;

	outer = stack;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if (outer->value == inner->value)
				quit();
			inner = inner->next;
		}
		outer = outer->next;
	}
}

void	quit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_stack(t_stack **stack)
{
	t_stack *temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
