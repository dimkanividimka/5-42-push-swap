/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstarov <dstarov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:39:43 by dmytro            #+#    #+#             */
/*   Updated: 2023/12/03 15:55:20 by dstarov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_not_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->data > stack->next->data)
			return (TRUE);
		stack = stack->next;
	}
	return (FALSE);
}

void	sort_three(t_stack **stack_a)
{
	if (is_not_sorted(*stack_a))
	{
		if ((*stack_a)->data == find_min_value(*stack_a))
		{
			rra(stack_a);
			sa(stack_a);
		}
		else if ((*stack_a)->data == find_max_value(*stack_a))
		{
			ra(stack_a);
			if (is_not_sorted(*stack_a))
				sa(stack_a);
		}
		else
		{
			if ((*stack_a)->next->data == find_min_value(*stack_a))
				sa(stack_a);
			else
				rra(stack_a);
		}
	}
}
