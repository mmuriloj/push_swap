/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:07:32 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/16 16:26:47 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_vars *vars, char c)
{
	int	aux;

	if (c == 'a')
	{
		aux = vars->stack_a.nums[0];
		vars->stack_a.nums[0] = vars->stack_a.nums[1];
		vars->stack_a.nums[1] = aux;
		write(1, "sa\n", 4);
	}
	else
	{
		aux = vars->stack_b.nums[0];
		vars->stack_b.nums[0] = vars->stack_b.nums[1];
		vars->stack_b.nums[1] = aux;
		write(1, "sb\n", 4);
	}
}

void	swap_both(t_vars vars)
{
	swap(&vars, 'a');
	swap(&vars, 'b');
}
