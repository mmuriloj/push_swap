/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countingsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:37:31 by mumontei          #+#    #+#             */
/*   Updated: 2022/12/16 20:01:26 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static int	max_element(int *arr, int n)
{
	int	i;
	int	max;

	max = arr[n - 1];
	i = n - 1;
	while (i >= 0)
	{
		if (arr[i] > max)
			max = arr[i];
		i--;
	}
	return (max);
}

static int	min_element(int *arr, int n)
{
	int	i;
	int	min;

	min = arr[n - 1];
	i = n - 1;
	while (i >= 0)
	{
		if (arr[i] < min)
			min = arr[i];
		i--;
	}
	return (min);
}

static int *acumulative_counting(int *arr, int n)
{
	int	i;

	i = 1;
	while (i <= n)
	{
		arr[i] = arr[i - 1] + arr[i];
		i++;
	}
	return (arr);
}


int *countingsort(int *arr, int n, int range)
{
	int	*count_arr;
	int	*output_arr;
	int	i, j;

	printf("range: 0-%d\n", range);
	count_arr = malloc(range * sizeof(int));
	output_arr = malloc(n * sizeof(int));
	i = -1;
	printf("[count_array]:\n");
	i = -1;
	while (++i < range)
		count_arr[i] = 0;
	i = -1;
	j = -1;
	while (++i < n)
	{
		j = arr[i];
		count_arr[j] = count_arr[j] + 1;
	}
	count_arr = acumulative_counting(count_arr, range);
	j = -1;
	/*while (++j <= range)
		printf("%d ", count_arr[j]);
	printf("\n");*/
	i = -1;
	while (++i < n-1)
	{
		j = -1;
		while (j < range)
		{
			
		}
		if (arr[i])
		output_arr[i+1] = 
	}
	free(count_arr);
	return (output_arr);
}

int main(void)
{
	int arr[7];
	int n;
	int max, min; 
	
	arr[0] = 4;
	arr[1] = 2;
	arr[2] = 2;
	arr[3] = 8;
	arr[4] = 3;
	arr[5] = 3;
	arr[6] = 1;

	n = sizeof(arr) / sizeof(arr[0]);
	max = max_element(arr, n);
	min = min_element(arr, n);
	countingsort(arr, n, max);
}