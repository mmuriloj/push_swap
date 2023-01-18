/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:41:27 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/18 19:01:40 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push_a(t_vars *vars)
{
	int	*new_a;
	int	*new_b;
	int *ptr_a;
	int *ptr_b;
	int	i;

	ptr_a = &vars->stack_a.nums[0];
	ptr_b = &vars->stack_b.nums[0];
	if (vars->len_b == 0)
		return ;
	new_a = ft_calloc(vars->len_a + 1, sizeof(int));
	new_b = ft_calloc(vars->len_b - 1, sizeof(int));
	if (!new_a || !new_b)
		exit(EXIT_FAILURE);
	vars->len_a++;
	vars->len_b--;
	new_a[0] = vars->stack_b.nums[0];
	i = 0;
	while(++i < vars->len_a)
		new_a[i] = vars->stack_a.nums[i - 1];
	vars->stack_a.nums = new_a;
	free(ptr_a);
	i = 0;
	while(i++ < vars->len_b - 1)
		new_b[i - 1] = vars->stack_a.nums[i];
	vars->stack_b.nums = new_b;
	free(ptr_b);
	ft_printf("pa\n");
}

void push_b(t_vars *vars)
{
	int	*new_a;
	int	*new_b;
	int *ptr_a;
	int *ptr_b;
	int	i;

	ptr_a = &vars->stack_a.nums[0];
	ptr_b = &vars->stack_b.nums[0];
	if (vars->len_a == 0)
		return ;
	new_b = ft_calloc(vars->len_b + 1, sizeof(int));
	new_a = ft_calloc(vars->len_a - 1, sizeof(int));
	if (!new_a || !new_b)
		exit(EXIT_FAILURE);
	vars->len_b++;
	vars->len_a--;
	new_b[0] = vars->stack_a.nums[0];
	i = 0;
	while(++i < vars->len_b)
		new_b[i] = vars->stack_b.nums[i - 1];
	vars->stack_b.nums = new_b;
	free(ptr_b);
	i = 1;
	while(i <= vars->len_a)
	{
		new_a[i - 1] = vars->stack_a.nums[i];
		i++;
	}
	vars->stack_a.nums = new_a;
	free(ptr_a);
	ft_printf("pb\n");
}

