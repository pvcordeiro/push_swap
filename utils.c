/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:24:54 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/27 18:27:28 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_null(t_stack **stack)
{
	return (!stack || !(*stack) || !(*stack)->next);
}



void	quit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
