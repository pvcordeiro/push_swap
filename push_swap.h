/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:59:48 by paude-so          #+#    #+#             */
/*   Updated: 2024/11/26 18:16:27 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

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
void	init_stack(int argc, char **argv, t_stack **stack);
void	add_to_stack(t_stack **stack, int value);
t_stack	*new_node(int value);
void	free_stack(t_stack **stack);
void	quit(void);
void	check_duplicates(t_stack *stack);
int		ft_atoi(const char *str);
int		is_null(t_stack **stack);
char	**split(char *s);
void	radix(t_stack **a, t_stack **b);
int		stack_size(t_stack *stack);
void	sort_ten(t_stack **a, t_stack **b);
int		is_sorted(t_stack *stack);
void	*ft_calloc(size_t nmemb, size_t size);
void	normalize_stack(t_stack *stack);

#endif