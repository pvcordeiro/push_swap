/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:59:12 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/25 17:47:49 by paude-so         ###   ########.fr       */
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
			quit();
		temp = argv;
		while (*temp)
			temp++;
		init_stack(temp - argv + 1, argv - 1, a);
		free_split(argv);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	
	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		single_string(argv, &a);
	else
		init_stack(argc, argv, &a);
	check_duplicates(a);
	radix(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
