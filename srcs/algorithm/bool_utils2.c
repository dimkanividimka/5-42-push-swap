/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstarov <dstarov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 11:59:45 by dstarov           #+#    #+#             */
/*   Updated: 2023/12/03 15:23:06 by dstarov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	in_first_half_a(t_stack *node, t_stack *stack_a)
{
	return (node->index < find_mid_index(stack_a));
}

int	in_first_half_b(t_stack *stack_b, int index_in_b)
{
	return (index_in_b < find_mid_index(stack_b));
}
