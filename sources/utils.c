/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:24:56 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/20 16:29:20 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_digit(const char *str)
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
					exit(EXIT_FAILURE);
				j++;
			}
		}
		else if ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
			exit(EXIT_FAILURE);
		i++;
	}
}

static void	check_if_only_numbers(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		check_digit(argv[i]);
		i++;
	}
}

void	init_vars(t_vars *vars, char *argv[], int argc)
{
	int	i;

	vars->stack_a.nums = NULL;
	vars->stack_b.nums = NULL;
	vars->len_a = argc - 1;
	vars->len_b = 0;
	vars->sorted = ft_calloc(vars->len_a, sizeof(int));
	vars->stack_a.nums = ft_calloc(vars->len_a, sizeof(int));
	if (!vars->sorted || !vars->stack_a.nums)
		exit(EXIT_FAILURE);
	i = -1;
	while (i++ < vars->len_a - 1)
	{
		vars->sorted[i] = ft_atoi(argv[i + 1]);
		vars->stack_a.nums[i] = ft_atoi(argv[i + 1]);
	}
	vars->min = get_min_value(vars->sorted, vars->len_a);
	vars->max = get_max_value(vars->sorted, vars->len_a);
	if (vars->min < 0)
	{
		i = -1;
		while (++i < vars->len_a)
			vars->sorted[i] = vars->sorted[i] - vars->min;
	}
	is_sorted(argc, vars);
}

void	check_args(int argc, char *argv[])
{
	int	i;

	if (argc < 2)
		exit(EXIT_FAILURE);
	else
		check_if_only_numbers(argc, argv);
	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 10 || ft_atoi(argv[i]) >= MAX_INT)
			exit(EXIT_FAILURE);
		i++;
	}
}

void	is_sorted(int argc, t_vars *vars)
{
	int	i;

	vars->is_sorted = TRUE;
	radixsort(vars);
	i = 0;
	while (i < argc - 2)
	{
		if (vars->stack_a.nums[i] != vars->sorted[i])
		{
			vars->is_sorted = FALSE;
			break ;
		}
		i++;
	}
	if (vars->is_sorted)
		exit(0);
}
