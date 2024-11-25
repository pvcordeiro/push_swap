/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:05:25 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/22 21:06:08 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (1);
	stack_a = initialize_stack(argc, argv);
	if (!a || issorted(a))
		return (free_stack(a), 1)
	b = malloc(sizeof(t_stack));
	if (!b)
		return (free_stack(a), write(2, "Error\n", 6), 1);
	b->top = NULL;
	b->size = 0;
	if (a->size <= 5)
		sort_small(a, b);
	else
		sort_large(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
