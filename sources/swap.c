/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:07:32 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/25 19:33:11 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(char c, t_vars *vars)
{
	int	aux;

	if (c == 's')
		swap_both(vars);
	else if (c == 'a')
	{
		if (vars->len_a < 2)
			return ;
		aux = vars->stack_a.nums[0];
		vars->stack_a.nums[0] = vars->stack_a.nums[1];
		vars->stack_a.nums[1] = aux;
		ft_printf("sa\n");
		return ;
	}
	else if (c == 'b')
	{
		if (vars->len_b < 2)
			return ;
		aux = vars->stack_b.nums[0];
		vars->stack_b.nums[0] = vars->stack_b.nums[1];
		vars->stack_b.nums[1] = aux;
		ft_printf("sb\n");
		return ;
	}
	ft_printf("ss\n");
}

void	swap_both(t_vars *vars)
{
	swap('a', vars);
	swap('b', vars);
}

/*
void	swap(char c, t_vars *vars)
{
	int	aux;
	int	s_flag;

	s_flag = FALSE;
	if (c == 's' && vars->len_a >= 2 && vars->len_b >= 2)
		s_flag = TRUE;
	else if (c == 's')
		return ;
	if (c == 'a' || s_flag)
	{
		if (vars->len_a < 2)
			return ;
		aux = vars->stack_a.nums[0];
		vars->stack_a.nums[0] = vars->stack_a.nums[1];
		vars->stack_a.nums[1] = aux;
		if (c == 'a')
		{
			ft_printf("sa\n");
			return ;
		}
	}
	if (c == 'b' || s_flag)
	{
		if (vars->len_b < 2)
			return ;
		aux = vars->stack_b.nums[0];
		vars->stack_b.nums[0] = vars->stack_b.nums[1];
		vars->stack_b.nums[1] = aux;
		if (c == 'b')
		{
			ft_printf("sb\n");
			return ;
		}
	}
	ft_printf("ss\n");
}
*/