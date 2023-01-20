/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:02:07 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/20 15:07:42 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_num_stack(t_vars *vars)
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

/*void	push_swap(t_vars *vars)
{
	
}*/