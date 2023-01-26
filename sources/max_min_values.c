/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:03:00 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/25 21:54:13 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max_value(int *array, int n)
{
	int	i;
	int	max;

	max = array[0];
	i = 0;
	while (++i < n)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

int	get_min_value(int *array, int n)
{
	int	i;
	int	min;
	int	value;

	min = array[0];
	i = -1;
	while (++i < n)
	{
		value = array[i];
		if (value < min)
			min = array[i];
	}
	return (min);
}

long int	ascii_to_long_int(const char *str)
{
	int			sign;
	long int	result;

	result = 0;
	sign = 1;
	while (((*str >= '\t' && *str <= '\r') || *str == ' ') && *str != '\0')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1 * sign;
		str++;
		if (*str == '-' || *str == '+')
			return (0);
	}
	while (ft_isdigit(*str))
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	return (sign * result);
}

void	check_range(int argc, char *argv[], t_vars *vars)
{
	long int	number;
	int			i;

	i = 0;
	while (++i < argc)
	{
		number = ascii_to_long_int(argv[i]);
		if (number > MAX_INT || number < MIN_INT)
		{
			error_msg(0, vars);
			exit(0);
		}
	}
}
