/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:24:18 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/25 19:40:49 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdio.h> //apagar

# define TRUE 1
# define FALSE 0
# define MAX_INT 2147483647
# define MIN_INT -2147483648
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
}	t_stack;

typedef struct s_vars
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		len_a;
	int		len_b;
	int		max;
	int		min;
	int		*sorted;
	int		*sorted_pos;
	int		is_sorted;
	int		min_a;
}	t_vars;

void	bubble_sort(int *arr, int n);
void	check_range(int argc, char *argv[], t_vars *vars);
void	countingsort(t_vars *vars, int place);
void	init_vars(t_vars *arr, char *argv[], int argc);
int		get_max_value(int *array, int n);
int		get_min_value(int *array, int n);
void	swap_both(t_vars *vars);
void	swap(char c, t_vars *vars);
void	push_a(int i, t_vars *vars);
void	push_b(int i, t_vars *vars);
void	rotate(char c, t_vars *vars);
void	reverse_rotate(char c, t_vars *vars);
void	three_sort(t_vars *vars);
void	check_args(int argc, char *argv[], t_vars *vars);
void	is_sorted(int argc, t_vars *vars);
void	five_sort(t_vars *vars);
void	insert_sort(t_vars *vars);
int		sorted_pos(int num, t_vars *vars);
void	big_sort(int max, int num, int max_bits, t_vars *vars);
void	error_msg(int num, t_vars *vars);
#endif