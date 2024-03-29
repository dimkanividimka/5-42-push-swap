/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstarov <dstarov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:04:24 by dmytro            #+#    #+#             */
/*   Updated: 2023/12/03 15:54:45 by dstarov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/**
 * //move_first_half_a_second_half_b*
*/
void	move_first_second(t_stack **stack_a, t_stack **stack_b, int weight_a,
		int weight_b)
{
	while (weight_a-- != 0)
		ra(stack_a);
	while (weight_b-- != 0)
		rrb(stack_b);
}

void	move_second_first(t_stack **stack_a, t_stack **stack_b, int weight_a,
		int weight_b)
{
	while (weight_a--)
		reverse_rotate_stack(stack_a, TRUE);
	while (weight_b--)
		rotate_stack(stack_b, TRUE);
}

void	move_second_half(t_stack **stack_a, t_stack **stack_b, int weight_a,
		int weight_b)
{
	if (weight_a <= weight_b)
	{
		weight_b -= weight_a;
		while (weight_a-- != 0)
			rrr(stack_a, stack_b);
		while (weight_b-- != 0)
			reverse_rotate_stack(stack_b, TRUE);
	}
	else if (weight_b < weight_a)
	{
		weight_a -= weight_b;
		while (weight_b-- != 0)
			rrr(stack_a, stack_b);
		while (weight_a-- != 0)
			reverse_rotate_stack(stack_a, TRUE);
	}
}

void	move_first_half(t_stack **stack_a, t_stack **stack_b, int weight_a,
		int weight_b)
{
	if (weight_a <= weight_b)
	{
		weight_b -= weight_a;
		while (weight_a-- != 0)
			rr(stack_a, stack_b);
		while (weight_b-- != 0)
			rb(stack_b);
	}
	else
	{
		weight_a -= weight_b;
		while (weight_b-- != 0)
			rr(stack_a, stack_b);
		while (weight_a-- != 0)
			ra(stack_a);
	}
}
