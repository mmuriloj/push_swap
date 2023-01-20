/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:18:54 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/20 14:19:03 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate_a(char c, t_vars *vars)
{
	int	i;
	int	tmp;
	int	*arr;
	int	r_flag;

	r_flag = FALSE;
	if (c == 'r')
		r_flag = TRUE;
	arr = vars->stack_a.nums;
	tmp = arr[vars->len_a - 1];
	i = vars->len_a - 1;
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	arr[0] = tmp;
	if (r_flag == FALSE)
		ft_printf("ra\n");
}

static void	reverse_rotate_b(char c, t_vars *vars)
{
	int	i;
	int	tmp;
	int	*arr;
	int	r_flag;

	r_flag = FALSE;
	if (c == 'r')
		r_flag = TRUE;
	arr = vars->stack_b.nums;
	tmp = arr[vars->len_b - 1];
	i = vars->len_b - 1;
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	arr[0] = tmp;
	if (r_flag == FALSE)
		ft_printf("rb\n");
}

static void	reverse_rotate_both(t_vars *vars)
{
	if (vars->len_a > 1 && vars->len_b > 1)
	{
		reverse_rotate_a('r', vars);
		reverse_rotate_b('r', vars);
		ft_printf("rr\n");
	}
}

void	reverse_rotate(char c, t_vars *vars)
{
	if (c == 'r' && vars->len_a > 1 && vars->len_b > 1)
	{
		reverse_rotate_both(vars);
		return ;
	}
	else if (c == 'a')
		reverse_rotate_a('n', vars);
	else if (c == 'b')
		reverse_rotate_b('n', vars);
}
