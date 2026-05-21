/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:37:30 by gerramir          #+#    #+#             */
/*   Updated: 2026/05/21 15:42:39 by gerramir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

/////////////////////////// list_stack
typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

/////////////////////////// functions
int					ft_flag(char *av);
int					ft_verify_digit(char *str);
int					is_alpha(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(const char *nptr);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
t_list				*ft_lstnew(void *content);

#endif