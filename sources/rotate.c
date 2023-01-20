/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:57:30 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/19 14:57:35 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:43:51 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/19 14:56:45 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_a(char c, t_vars *vars)
{
	int	i;
	int	tmp;
	int	*arr;
	int	r_flag;

	r_flag = FALSE;
	if (vars->len_a < 2)
		return ;
	if (c == 'r')
		r_flag = TRUE;
	arr = vars->stack_a.nums;
	tmp = arr[0];
	i = 0;
	while (i < vars->len_a - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[vars->len_a - 1] = tmp;
	if (r_flag == FALSE)
		ft_printf("ra\n");
}

static void	rotate_b(char c, t_vars *vars)
{
	int	i;
	int	tmp;
	int	*arr;
	int	r_flag;

	r_flag = FALSE;
	if (vars->len_b < 2)
		return ;
	if (c == 'r')
		r_flag = TRUE;
	arr = vars->stack_b.nums;
	tmp = arr[0];
	i = 0;
	while (i < vars->len_b - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[vars->len_b - 1] = tmp;
	if (r_flag == FALSE)
		ft_printf("rb\n");
}

static void	rotate_both(t_vars *vars)
{
	if (vars->len_a > 1 && vars->len_b > 1)
	{
		rotate_a('r', vars);
		rotate_b('r', vars);
		ft_printf("rr\n");
	}
}

void	rotate(char c, t_vars *vars)
{
	if (c == 'r' && vars->len_a > 1 && vars->len_b > 1)
	{
		rotate_both(vars);
		return ;
	}
	else if (c == 'a')
		rotate_a('n', vars);
	else if (c == 'b')
		rotate_b('n', vars);
}
