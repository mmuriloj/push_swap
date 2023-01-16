/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:24:18 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/16 16:20:07 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "../libft/includes/libft.h"
# include <stdio.h> //apagar

# define SA "sa"
# define SB "sb"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RRA "rra"
# define RRB "rrb"

typedef struct s_stack
{
	int	*nums;
	int	last_num;
} t_stack;


typedef struct s_vars
{
	t_stack	stack_a;
	t_stack	stack_b;
	int	n_elem;
	int	max;
	int	min;
	int	*sorted;
}	t_vars;

void	countingsort(t_vars *vars, int place);
void	init_vars(t_vars *arr, char *argv[], int argc);
int		get_max_value(int *array, int n);
int		get_min_value(int *array, int n);
void	radixsort(t_vars *vars);
void	print_array(t_vars *vars);
void	swap(t_vars *vars, char c);
#endif