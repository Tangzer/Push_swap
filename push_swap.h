/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tverdood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:34:30 by tverdood          #+#    #+#             */
/*   Updated: 2022/07/05 14:34:34 by tverdood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR 1

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdarg.h>

enum
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

typedef struct s_list
{
	void			*content;
	int				index;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_ps
{
	t_list	*stack_a;
	t_list	*stack_b;
	size_t	ops;
}	t_ps;

/*utils*/
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
int		ft_is_digit(char *arg);
long	ft_atoi(const char *str);

/*utils_lst*/
int		lst_size(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*lst_max(t_list *head);
t_list	*lst_min(t_list *head);
bool	lst_is_already_sorted(t_list *head);

/*lst*/
t_list	*ft_lstnew(int *new_content);
t_list	*lst_last(t_list *lst);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lst_add_back(t_list **address_lst, t_list *new_node);
void	ft_lst_add_front(t_list **alst, t_list *new_node);

/*sort_small*/
int		still_not_sorted(t_list *node);
void	sort_small(t_ps *ps);

/*operations*/
void	swap(t_list **head);
void	rotate(t_list **head);
void	reverse_rotate(t_list **head);
void	push(t_list **src, t_list **dst);

/*reste*/
void	do_op(int op, t_ps *ps);
int		parsing(char **argv);
void	radix_sort(t_ps *ps);

#endif
