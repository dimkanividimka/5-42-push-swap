/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstarov <dstarov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:03:25 by dstarov           #+#    #+#             */
/*   Updated: 2023/12/03 17:04:52 by dstarov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (error_check(argc, argv))
		return (write(2, "Error\n", 6));
	stack_a = get_input(argc, argv);
	sort(&stack_a, &stack_b);
	ft_free(&stack_a, &stack_b);
	return (0);
}
