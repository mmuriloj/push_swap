/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:11:14 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/16 18:16:25 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	p_arr(t_vars *vars);

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc < 3)
		return (0);
	init_vars(&vars, argv, argc);
	radixsort(&vars);
	//p_arr(&vars);			//apagar
	//swap(&vars, 'a');		//apagar
	push_a(&vars);
	p_arr(&vars);			//apagar
	//print_array(&vars);		//apagar
	free(vars.sorted);
	free(vars.stack_a.nums);
}

void	p_arr(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->n_elem)
	{
		if (vars->min < 0)
			vars->stack_a.nums[i] = vars->stack_a.nums[i] + vars->min;
		else
			vars->stack_a.nums[i] = vars->stack_a.nums[i];
	}
	i = -1;
	while (++i < vars->n_elem)
		printf("%d ", vars->stack_a.nums[i]);
	printf("\n\n");
}
