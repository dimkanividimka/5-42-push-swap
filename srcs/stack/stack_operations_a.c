/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstarov <dstarov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:15:09 by dstarov           #+#    #+#             */
/*   Updated: 2023/12/03 20:01:00 by dstarov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **stack)
{
	stack_swap(stack, TRUE);
}

void	ra(t_stack **stack)
{
	rotate_stack(stack, TRUE);
}

void	rra(t_stack **stack)
{
	reverse_rotate_stack(stack, TRUE);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	stack_push_to(stack_b, stack_a);
}
