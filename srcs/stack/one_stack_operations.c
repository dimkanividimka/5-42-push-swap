/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_stack_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstarov <dstarov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:59:39 by dmytro            #+#    #+#             */
/*   Updated: 2023/12/03 19:54:29 by dstarov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * reverse two upper elements in stack
 * prints {sa} or {sb}
 * @param stack stack to swap
 * @param needs_to_print
*/
void	stack_swap(t_stack **stack, int needs_to_print)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if (needs_to_print)
	{
		if ((*stack)->is_a)
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
	}
}

/**
 * pushes upper element from stack_from to stack_to
 * prints {pb, pa}
 * @param stack_from
 * @param stack_to
*/
void	stack_push_to(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*to_push;

	if (!*stack_from)
		return ;
	to_push = *stack_from;
	(*stack_from)->is_a = !(*stack_from)->is_a;
	*stack_from = (*stack_from)->next;
	if (!*stack_to)
		ft_lstadd_back(stack_to, to_push);
	else
		ft_lstadd_front(stack_to, to_push);
	if ((*stack_to)->is_a)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

/**
 * rotates stack, shifting all elements one position forward
 * 1    2 
 * 2    3
 * 3 => 4
 * 4    5
 * 5    1
 * prints {ra, rb}
 * @param stack
 * @param needs_to_print
*/
void	rotate_stack(t_stack **stack, int needs_to_print)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	ft_lstadd_back(stack, tmp);
	if (needs_to_print)
	{
		if (tmp->is_a)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
}

/**
 * reversely rotates stack, shifting all elements one position forward
 * 1    5 
 * 2    1
 * 3 => 2
 * 4    3
 * 5    4
 * prints {ra, rb}
 * @param stack
 * @param needs_to_print
*/
void	reverse_rotate_stack(t_stack **stack, int needs_to_print)
{
	t_stack	*tmp;
	t_stack	*last_elem_in_stack;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last_elem_in_stack = tmp->next;
	tmp->next = NULL;
	last_elem_in_stack->next = *stack;
	*stack = last_elem_in_stack;
	if (needs_to_print)
	{
		if ((*stack)->is_a)
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
	}
}
