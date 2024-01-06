/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstarov <dstarov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:53:02 by dmytro            #+#    #+#             */
/*   Updated: 2023/12/03 12:09:32 by dstarov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*find_by_value(t_stack *stack, int value)
{
	while (stack && stack->data != value)
		stack = stack->next;
	return (stack);
}

t_stack	*get_last_elem(t_stack *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	find_mid_index(t_stack *stack)
{
	int	size;

	size = ft_lstsize(stack);
	if (size % 2 == 0)
		return (size / 2);
	return (size / 2 + 1);
}
