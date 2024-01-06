/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstarov <dstarov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:56:10 by dmytro            #+#    #+#             */
/*   Updated: 2023/12/02 21:54:33 by dstarov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_stack **stack)
{
	stack_swap(stack, TRUE);
}

void	rb(t_stack **stack)
{
	rotate_stack(stack, TRUE);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	stack_push_to(stack_a, stack_b);
}

void	rrb(t_stack **stack)
{
	reverse_rotate_stack(stack, TRUE);
}
