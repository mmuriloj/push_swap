/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:24:56 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/25 23:13:08 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_digit(const char *str, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[0] == '-' && ft_strlen(str) > 1)
		{
			i++;
			j = 1;
			while (str[j] != '\0')
			{
				if (str[j] < '0' || str[j] > '9')
					error_msg(0, vars);
				j++;
			}
		}
		else if ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
			error_msg(0, vars);
		i++;
	}
}

static void	check_if_only_numbers(int argc, char *argv[], t_vars *vars)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		check_digit(argv[i], vars);
		i++;
	}
}

void	init_vars(t_vars *vars, char *argv[], int argc)
{
	int	i;

	vars->stack_b.nums = NULL;
	vars->len_a = argc - 1;
	vars->len_b = 0;
	vars->sorted = ft_calloc(vars->len_a, sizeof(int));
	vars->stack_a.nums = ft_calloc(vars->len_a, sizeof(int));
	if (!vars->sorted || !vars->stack_a.nums)
		error_msg(2, vars);
	i = -1;
	while (i++ < vars->len_a - 1)
	{
		vars->stack_a.nums[i] = ft_atoi(argv[i + 1]);
		vars->sorted[i] = ft_atoi(argv[i + 1]);
	}
	bubble_sort(vars->sorted, argc - 1);
	vars->min = get_min_value(vars->sorted, vars->len_a);
	vars->max = get_max_value(vars->sorted, vars->len_a);
	if (vars->min < 0)
	{
		i = -1;
		while (++i < vars->len_a)
			vars->stack_a.nums[i] = vars->stack_a.nums[i] - vars->min;
	}
	is_sorted(argc, vars);
}

void	check_args(int argc, char *argv[], t_vars *vars)
{
	int	i;
	int	j;

	if (argc < 2)
		exit(EXIT_FAILURE);
	else
		check_if_only_numbers(argc, argv, vars);
	check_range(argc, argv, vars);
	i = argc - 1;
	while (i >= 2)
	{
		j = i;
		while (j-- > 1)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				error_msg(0, vars);
		}
		i--;
	}
}

void	is_sorted(int argc, t_vars *vars)
{
	int	i;

	vars->is_sorted = TRUE;
	i = 0;
	while (i < argc - 2)
	{
		if (vars->stack_a.nums[i] > vars->stack_a.nums[i + 1])
		{
			vars->is_sorted = FALSE;
			break ;
		}
		i++;
	}
	if (vars->is_sorted)
	{
		free(vars->sorted);
		free(vars->stack_a.nums);
		exit(EXIT_FAILURE);
	}
}
