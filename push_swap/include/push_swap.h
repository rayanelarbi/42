/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:57:30 by rlarbi            #+#    #+#             */
/*   Updated: 2025/04/13 14:37:26 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nb;
	int				push_cost;
	int				i;
	bool			cheapest;
	bool			above_median;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}					t_stack;

t_stack				*get_last_block(t_stack *stack);
t_stack				*find_max(t_stack *stack);
t_stack				*find_min(t_stack *stack);
int					stack_size(t_stack *stack);
bool				is_sorted(t_stack *stack);

void				sort_three(t_stack **a);
void				min_block_top(t_stack **a);
void				free_arr(char **arr);
void				print_error(void);

int					is_valid_number(char *arg);
int					has_duplicate(t_stack *a, int n);
void				free_stack(t_stack **stack);
void				free_errors(t_stack **a, char **arr, bool n);

char				**ft_split(const char *s, char c);

void				init_stack(t_stack **a, char **array, bool n);
t_stack				*get_cheapest(t_stack *stack);
void				push_cheapest(t_stack **stack, t_stack *block,
						char stack_name);

void				set_cheapest(t_stack **a);
void				set_index(t_stack *a);
void				a_initializer(t_stack *a, t_stack *b);

void				b_initializer(t_stack *a, t_stack *b);

void				turk_algorithm(t_stack **a, t_stack **b);

/*--------------------INSTRUCTIONS--------------------*/
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);

void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);

void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **b, t_stack **a);

#endif
