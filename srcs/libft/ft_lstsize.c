/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstarov <dstarov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:45:09 by dmytro            #+#    #+#             */
/*   Updated: 2023/12/03 12:10:47 by dstarov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	t_stack	*x;
	int		size;

	x = lst;
	size = 0;
	while (x != NULL)
	{
		size++;
		x = x->next;
	}
	return (size);
}
