/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:59:48 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/27 18:18:13 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// debug
// # define HERE write(2, "HERE\n", 5)
// # define THERE write(2, "THERE\n", 6)

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
int		init_stack(char **argv, t_stack **stack);
void	free_stack(t_stack **stack);
void	quit(void);
int		check_duplicates(t_stack **stack);
int		ft_atoi(char **str);
int		is_null(t_stack **stack);
void	radix(t_stack **a, t_stack **b);
int		stack_size(t_stack *stack);
void	sort_ten(t_stack **a, t_stack **b);
void	normalize_stack(t_stack *stack);
void	merge_sort(t_stack **a, t_stack **b);

#endif