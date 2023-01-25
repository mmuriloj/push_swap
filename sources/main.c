/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:11:14 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/25 19:40:43 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_vars	vars;

	check_args(argc, argv, &vars);
	init_vars(&vars, argv, argc);
	if (argc <= 4)
		three_sort(&vars);
	else if (argc <= 6)
		five_sort(&vars);
	else
		big_sort(0, 0, 0, &vars);
	free(vars.sorted);
	free(vars.stack_a.nums);
	free(vars.stack_b.nums);
}
