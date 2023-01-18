/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumontei <mumontei@42.sp.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:24:18 by mumontei          #+#    #+#             */
/*   Updated: 2023/01/18 19:59:45 by mumontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "../libft/includes/libft.h"
# include <stdio.h> //apagar

# define TRUE 1
# define FALSE 0
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
	int	len_a;
	int	len_b;
	int	max;
	int	min;
	int	*sorted;
}	t_vars;

void	countingsort(t_vars *vars, int place);
void	init_vars(t_vars *arr, char *argv[], int argc);
int		get_max_value(int *array, int n);
int		get_min_value(int *array, int n);
void	radixsort(t_vars *vars);
void	print_sorted(t_vars *vars); //apagar
void	swap(char c, t_vars *vars);
void	push_a(t_vars *vars);
void	push_b(t_vars *vars);
//int		*realloc_stack(int *stack, unsigned int len, int size);
//int		stack_length(int *stack);
#endif