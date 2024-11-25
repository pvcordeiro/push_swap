/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:04:50 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/22 19:29:29 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int             value;
	struct s_node   *next;
}	t_node;

typedef struct s_stack
{
	t_node  *top;
	int     size;
}	t_stack;

// Stack operations
void	push(t_stack *src, t_stack *dest, char stack_name);
void	swap(t_stack *stack, char stack_name);
void	rotate(t_stack *stack, char stack_name);
void	reverse_rotate(t_stack *stack, char stack_name);

// Sorting algorithms
void	sort_small(t_stack *a, t_stack *b);
void	sort_large(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);

// Utility functions
t_stack	*initialize_stack(int argc, char **argv);
void	free_stack(t_stack *stack);
void	print_instruction(const char *instruction);
int		is_sorted(t_stack *stack);

#endif