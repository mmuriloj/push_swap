/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:11:14 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/18 17:13:10 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack_a(t_vars *vars);
void	print_stack_b(t_vars *vars);

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc < 3)
		return (0);
	init_vars(&vars, argv, argc);
	radixsort(&vars);
	//print_sorted(&vars);		//apagar

	//swap('a', &vars);		//apagar
	print_stack_a(&vars);
	int i = -1;
	while (++i < 8)
	{
		push_b(&vars);
		print_stack_a(&vars);
		print_stack_b(&vars);
	}
	print_stack_a(&vars);
	//swap('b', &vars);
	//swap('b', &vars);
	//swap('b', &vars);
	print_stack_b(&vars);
	//stack_length(vars.stack_a.nums);
	free(vars.sorted);
	//free(vars.stack_a.nums);
	//free(vars.stack_b.nums);
}

void	print_stack_a(t_vars *vars)
{
	int *ptr;
	
	ptr = vars->stack_a.nums;
	ft_printf("stack A: ", *ptr);
	while(*ptr)
	{
		ft_printf("%d ", *ptr);
		ptr++;
	}
	printf("\n");
}

void	print_stack_b(t_vars *vars)
{
	int *ptr;
	
	ptr = vars->stack_b.nums;
	ft_printf("stack B: ", *ptr);
	while(*ptr)
	{
		ft_printf("%d ", *ptr);
		ptr++;
	}
	printf("\n");
}