/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstarov <dstarov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:01:16 by dmytro            #+#    #+#             */
/*   Updated: 2023/12/03 17:36:19 by dstarov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TRUE 1
# define FALSE 0
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	int				index;
	unsigned int	weight;
	struct s_stack	*next;
	int				is_a;
}					t_stack;

/***********************libft***********************/
char		**ft_split(char const *s, char c);
int			ft_atoi(const char *str);
long		ft_atoi_long(const char *nptr);
int			ft_lstsize(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack		*ft_lstnew(int data);
int			ft_strcmp(char *s1, char *s2);
size_t		ft_strlen(const char *str);
int			ft_isdigit(int a);

/***********************error checks************************/
int			digit_check(char *str);
int			range_check(char *str);
int			duplicite_check(int argc, char **str, int flag);
int			is_argv_error(int argc, char **argv);
int			error_check(int argc, char **argv);

/***********************input utils***********************/
t_stack		*array_to_stack(const int *array, int len, int is_a);
t_stack		*get_input(int argc, char **argv);
int			*split_to_ints(char **str_splitted, int len);
int			*chars_to_ints(char **argv, int len);

/***********************sort************************/
void		sort(t_stack **stack_a, t_stack **stack_b);
void		sort_three(t_stack **stack_a);
t_stack		*find_cheapest_elem(t_stack *stack);

/***********************sort utils************************/
int			is_not_sorted(t_stack *stack);
void		init_stack(t_stack *stack);
void		assign_weights(t_stack **stack_a, t_stack **stack_b);
int			find_min_value(t_stack *stack);
int			find_max_value(t_stack *stack);
t_stack		*get_max_elem(t_stack *stack);
t_stack		*get_min_elem(t_stack *stack);
t_stack		*find_by_value(t_stack *stack, int value);
t_stack		*get_last_elem(t_stack *stack);
int			get_future_index_in_a(int num, t_stack *stack_a);
int			find_future_index_in_b(int value, t_stack *stack_b);
int			calculate_weight(t_stack *elem_a, t_stack *stack_a,
				t_stack *stack_b, int future_index);
int			find_mid_index(t_stack *stack);

/*********************** one stack operations***********************/
void		pb(t_stack **stack_a, t_stack **stack_b);
void		sb(t_stack **stack);
void		rrb(t_stack **stack);
void		rb(t_stack **stack);
void		sa(t_stack **stack);
void		ra(t_stack **stack);
void		rra(t_stack **stack);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		stack_swap(t_stack **stack, int needs_to_print);
void		stack_push_to(t_stack **stack_from, t_stack **stack_to);
void		rotate_stack(t_stack **stack, int needs_to_print);
void		reverse_rotate_stack(t_stack **stack, int needs_to_print);

/*********************** two stacks operations***********************/
void		ss(t_stack **stack_a, t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);

/***********************bool-int utils***********************/
int			in_first_half_a(t_stack *node, t_stack *stack_a);
int			in_first_half_b(t_stack *stack_b, int index_in_b);
int			in_second_half_both(t_stack *node, t_stack *stack_a,
				t_stack *stack_b, int index_in_b);
int			in_first_half_both(t_stack *node, t_stack *stack_a,
				t_stack *stack_b, int index_in_b);
int			in_second_first(t_stack *node, t_stack *stack_a,
				t_stack *stack_b, int index_in_b);
int			in_first_second(t_stack *node, t_stack *stack_a,
				t_stack *stack_b, int index_in_b);
int			can_rotate_both(t_stack *node, t_stack *stack_a,
				t_stack *stack_b, int index_in_b);

/***********************moves***********************/
void		move_a_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *elem);
void		move_b_to_a(t_stack **stack_b, t_stack **stack_a, t_stack *elem);
void		move_min_to_top(int index, t_stack **stack);
void		finalize_stack_a(t_stack **stack_a);

/***********************move utils***********************/
void		move_first_half(t_stack **stack_a, t_stack **stack_b,
				int weight_a, int weight_b);
void		move_second_half(t_stack **stack_a, t_stack **stack_b,
				int weight_a, int weight_b);
void		move_first_second(t_stack **stack_a, t_stack **stack_b,
				int weight_a, int weight_b);
void		move_second_first(t_stack **stack_a, t_stack **stack_b,
				int weight_a, int weight_b);

/***********************free memes************************/
void		ft_free_arr(char **arr);
void		free_stack(t_stack **stack);
void		ft_free(t_stack **stack_a, t_stack **stack_b);

#endif