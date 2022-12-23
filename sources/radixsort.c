/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:03:00 by mumontei          #+#    #+#             */
/*   Updated: 2022/12/23 10:38:25 by mumontei         ###   ########.fr       */
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

// Using counting sort to sort the elements in the basis of significant places
void	countingsort(t_vars *vars, int place)
{
	int	i;
	int	max;
	int	*output;
	int	*count;

	max = (vars->array[0] / place) % 10;
	//output = malloc((vars->n_elem + 1) * sizeof(int));
	output = ft_calloc(vars->n_elem + 1, sizeof(int));
	if (!output)
		exit(EXIT_FAILURE);
	i = 0;
	while (++i < vars->n_elem)
	{
		if (((vars->array[i] / place) % 10) > max)
			max = vars->array[i];
	}
	//count = malloc ((max + 1) * sizeof(int));
	count = ft_calloc(max + 1, sizeof(int));
	if (!count)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < max)
		count[i] = 0;
	i = -1;
	while (++i < vars->n_elem)
		count[(vars->array[i] / place) % 10]++;
	i = 0;
	//while (++i < 10)
	while (++i < max + 1)
		count[i] += count[i - 1];
	i = vars->n_elem;
	while (--i >= 0)
	{
		output[count[(vars->array[i] / place) % 10] - 1] = vars->array[i];
		count[(vars->array[i] / place) % 10]--;
	}
	i = -1;
	while (++i < vars->n_elem)
		vars->array[i] = output[i];
	free(output);
	free(count);
}

// Main function to implement radix sort
void	radixsort(t_vars *vars)
{
	int	max;
	int	place;

	max = get_max_value(vars->array, vars->n_elem);
	place = 1;
	while (max / place > 0)
	{
		countingsort(vars, place);
		place *= 10;
	}
}

// Print an array
static void	print_array(t_vars *vars)
{
	int	i;

	printf("\nSorted:\n");
	i = -1;
	while (++i < vars->n_elem)
	{
		if (vars->min < 0)
			vars->array[i] = vars->array[i] + vars->min;
		else
			vars->array[i] = vars->array[i];
	}
	i = -1;
	while (++i < vars->n_elem)
		printf("%d ", vars->array[i]);
	printf("\n\n");
}

// Driver code
int	main(int argc, char *argv[])
{
	t_vars vars;

	init_vars(&vars, argv, argc);
	radixsort(&vars);
	print_array(&vars);
	free(vars.array);
}

/*
#include "../includes/push_swap.h"
int get_max_value(int array[], int n)
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
int get_min_value(int array[], int n)
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
	return min;
}
// Using counting sort to sort the elements in the basis of significant places
void countingsort(int array[], int size, int place)
{
	int output[size + 1];
	int max = (array[0] / place) % 10;
	for (int i = 1; i < size; i++) 
	{
		if (((array[i] / place) % 10) > max)
			max = array[i];
	}
	int count[max + 1];
	for (int i = 0; i < max; ++i)
		count[i] = 0;
	for (int i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;
	
	// Calculate cumulative count
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];
	// Place the elements in sorted order
	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}
	for (int i = 0; i < size; i++)
		array[i] = output[i];
}
// Main function to implement radix sort
void radixsort(int array[], int size)
{
	// Get maximum element
	int max = get_max_value(array, size);
	// Apply counting sort to sort elements based on place value.
	for (int place = 1; max / place > 0; place *= 10)
	countingsort(array, size, place);
}
// Print an array
void print_array(int array[], int size, int min)
{
	int	i;
	i = -1;
	while (++i < size)
		array[i] = array[i] + min;
	for (int i = 0; i < size; ++i)
	{
		printf("%d  ", array[i]);
	}
	printf("\n");
}
// Driver code
int main()
{
	int array[] = {-3, 9, 8, 6, 1, -7, -6, 3, 5, -2, -4, -9, -10, 2, -5};
	int n = sizeof(array) / sizeof(array[0]);
	int min;
	
	min = get_min_value(array, n);
	if (min < 0)
	{
		for (int i = 0; i < n; i++)
		{
			array[i] = array[i] - min;
		}
	}
	radixsort(array, n);
	print_array(array, n, min);
}*/