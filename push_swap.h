/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:18:39 by mbesan            #+#    #+#             */
/*   Updated: 2022/02/18 00:02:20 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libs/gnl/get_next_line.h"
# include "libs/libft/libft.h"

# ifndef WRITABLE
#  define WRITABLE 1
# endif

# ifndef UNWRITABLE
#  define UNWRITABLE 0
# endif

# ifndef SUCCESS
#  define SUCCESS 1
# endif

# ifndef DEFAULT_INDEX
#  define DEFAULT_INDEX 0
# endif

# ifndef NO_FAVORITES
#  define NO_FAVORITES 1
# endif

# ifndef PUSH_SWAP
#  define PUSH_SWAP 1
# endif

# ifndef CHECKER
#  define CHECKER 0
# endif

# ifndef BR
#  define BR 0
# endif

# ifndef BRR
#  define BRR 1
# endif

# ifndef RR_RB
#  define RR_RB 0
# endif

# ifndef RR_RA
#  define RR_RA 1
# endif

# ifndef RRB_RA
#  define RRB_RA 2
# endif

# ifndef RRA_RB
#  define RRA_RB 3
# endif

# ifndef RRB_RRR
#  define RRB_RRR 4
# endif

# ifndef RRA_RRR
#  define RRA_RRR 5
# endif

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				index;
	int				value;
	int				median;
	int				fin;
	int				score_br;
	int				score_brr;
	int				score_ar;
	int				score_arr;
	int				ind[6];
	int				swap_flag;
	int				rrr_flag;
	int				min_ind;
	int				decision;
}					t_node;

typedef struct s_stacks
{
	t_node	*a;
	t_node	*b;
}					t_stacks;

typedef struct s_args
{
	char	**arg;
	char	**original;
}					t_args;

int				not_validated(char **arg);
int				unsorted_stack(t_node **stack);
int				decision(t_node **b, t_node **a);
int				unsorted_stack(t_node **stack);
int				*arg_sort(t_args *args, int *elem_number, int *split_flag,
					int exec);

long long int	atoi_limit_checker(const char *c);

char			**write_arg(int argc, char **argv, int *split_flag);

void			uroboros(t_node **list);
void			ft_error(t_args *args, int *split_flag);
void			destroy_arg(t_args *args, int *split_flag);
void			sorting(t_node **stack_a, t_node **stack_b, int elem_num);
void			free_recent(int *arr, t_node **a, t_node **b);
void			scoring(t_node **stack_a, t_node **stack_b);
void			execution(t_node **a, t_node **b, int index);
void			p_a(t_node **stack_a, t_node **stack_b, int wr);
void			p_b(t_node **stack_a, t_node **stack_b, int wr);
void			s_s(t_node **stack_a, t_node **stack_b, int wr);
void			rrr(t_node **stack_b, t_node **stack_a, int wr);
void			rr(t_node **stack_b, t_node **stack_a, int wr);
void			rr_a(t_node **stack_a, int wr);
void			rr_b(t_node **stack_b, int wr);
void			r_a(t_node **stack_a, int wr);
void			r_b(t_node **stack_b, int wr);
void			swap_b(t_node **stack_b);
void			swap_a(t_node **stack_a);
void			s_a(t_node **stack_a, int wr);
void			s_b(t_node **stack_b, int wr);

t_node			*list_developement(char **arg, int *arr, int e_num,
					t_node **stack_b);
t_node			*get_last(t_node *list);

#endif