/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:02:07 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/23 16:30:46 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_sort(t_vars *vars)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = vars->stack_a.nums[0];
	n2 = vars->stack_a.nums[1];
	n3 = vars->stack_a.nums[2];
	if (n1 > n2 && n3 > n1)
		swap('a', vars);
	else if (n1 > n2 && n2 > n3)
	{
		swap('a', vars);
		reverse_rotate('a', vars);
	}
	else if (n1 > n2 && n3 > n2)
		rotate('a', vars);
	else if (n1 < n3 && n2 > n3)
	{
		swap('a', vars);
		rotate('a', vars);
	}
	else if (n3 < n1 && n2 > n1)
		reverse_rotate('a', vars);
}

void	five_sort(t_vars *vars)
{
	int	min;
	
	min = get_min_value(vars->stack_a.nums, vars->len_a);
	while (vars->len_a > 3)
	{
		min = get_min_value(vars->stack_a.nums, vars->len_a);
		if (vars->stack_a.nums[0] == min)
			push_b(vars);
		if (vars->stack_a.nums[vars->len_a - 2] == min 
		|| vars->stack_a.nums[vars->len_a - 1] == min)
			reverse_rotate('a', vars);
		else
			rotate('a', vars);
	}
	three_sort(vars);
	push_a(vars);
	push_a(vars);
}

void insert_sort(t_vars *vars)
{
	int	min;
	int	*middle_pos;

	min = get_min_value(vars->stack_a.nums, vars->len_a);
	while (vars->len_a > 3)
	{
		if (vars->is_sorted == TRUE)
			printf("sorted\n");
		min = get_min_value(vars->stack_a.nums, vars->len_a);
		middle_pos = &vars->stack_a.nums[vars->len_a / 2 + 1];
		if (vars->stack_a.nums[0] == min)
			push_b(vars);
		else if (&min >= middle_pos)
			reverse_rotate('a', vars);
		else
			rotate('a', vars);
	}
	three_sort(vars);
	while (vars->len_b != 0)
		push_a(vars);

}