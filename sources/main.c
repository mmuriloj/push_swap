/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:11:14 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/20 18:28:19 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack_a(t_vars *vars);
void	print_stack_b(t_vars *vars);
void print_stacks(t_vars *vars);

int	main(int argc, char *argv[])
{
	t_vars	vars;

	check_args(argc, argv);
	init_vars(&vars, argv, argc);
	
	/*--------------------------------*/
	print_stacks(&vars);
	three_num_stack(&vars);
	print_stacks(&vars);
	/*------------------------*/
	free(vars.sorted);
	free(vars.stack_a.nums);
	free(vars.stack_b.nums);
}

void	print_stack_a(t_vars *vars)
{
	
	int	i;

	ft_printf("\tstack A: ");
	if (vars->len_a == 0)
	{
		printf("\n");
		return ;
	}
	i = 0;
	while (i < vars->len_a)
	{
		ft_printf("%d ", vars->stack_a.nums[i]);
		i++;
	}
	printf("\n");
}

void	print_stack_b(t_vars *vars)
{
	int i;
	
	ft_printf("\tstack B: ");
	if (vars->len_b == 0)
	{
		printf("\n");
		return ;
	}
	i = 0;
	while (i < vars->len_b)
	{
		ft_printf("%d ", vars->stack_b.nums[i]);
		i++;
	}
	printf("\n");
}

void print_stacks(t_vars *vars)
{
	print_stack_a(vars);
	print_stack_b(vars);
}