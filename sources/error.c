/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:31:53 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/25 16:50:55 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_msg(int num, t_vars *vars)
{
	write(2, "Error\n", 6);
	if (num == 1)
		free(vars->stack_a.nums);
	if ((num == 2))
	{
		free(vars->stack_a.nums);
		free(vars->sorted);
	}
	exit(EXIT_FAILURE);
}
