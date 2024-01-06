/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstarov <dstarov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 09:50:08 by dstarov           #+#    #+#             */
/*   Updated: 2023/12/03 15:56:39 by dstarov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	digit_check(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] == '\0')
		return (TRUE);
	while (str[i] != 0)
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-'
				|| str[i] == '+'))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	duplicite_check(int argc, char **str, int flag)
{
	int	i;
	int	j;

	if (flag == 2)
		i = 0;
	else if (flag == 1)
		i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j != argc)
		{
			if ((ft_atoi(str[i]) == ft_atoi(str[j])))
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

int	range_check(char *str)
{
	if (!(ft_atoi_long(str) >= -2147483648 && ft_atoi_long(str) <= 2147483647))
		return (1);
	return (0);
}
