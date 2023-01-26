/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:11:14 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/25 23:01:12 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc == 2 || (argc == 3 && \
		ascii_to_long_int(argv[1]) < ascii_to_long_int(argv[2])))
		return (0);
	check_args(argc, argv, &vars);
	init_vars(&vars, argv, argc);
	if (argc <= 3 && vars.is_sorted == FALSE)
		rotate('a', &vars);
	else if (argc <= 4)
		three_sort(&vars);
	else if (argc <= 6)
		five_sort(&vars);
	else
		big_sort(0, 0, 0, &vars);
	free(vars.sorted);
	free(vars.stack_a.nums);
	if (argc > 4)
		free(vars.stack_b.nums);
}
