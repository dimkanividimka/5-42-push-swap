/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stacks_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstarov <dstarov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:09:36 by dmytro            #+#    #+#             */
/*   Updated: 2023/12/03 15:56:19 by dstarov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * performs swap with two stacks simultaneously
 * @param stack_a
 * @param stack_b
*/
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	stack_swap(stack_a, FALSE);
	stack_swap(stack_b, FALSE);
	write(1, "ss\n", 3);
}

/**
 * performs rotate with two stacks simultaneously
 * @param stack_a
 * @param stack_b
*/
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_stack(stack_a, FALSE);
	rotate_stack(stack_b, FALSE);
	write(1, "rr\n", 3);
}

/**
 * performs reverse rotate with two stacks simultaneously
 * @param stack_a
 * @param stack_b
*/
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_stack(stack_a, FALSE);
	reverse_rotate_stack(stack_b, FALSE);
	write(1, "rrr\n", 4);
}
