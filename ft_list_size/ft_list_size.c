/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sucho <sucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 08:55:51 by sucho             #+#    #+#             */
/*   Updated: 2023/05/17 09:46:33 by sucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

// int	ft_list_size_recursive(t_list *begin_list)
// {
// 	if (begin_list == 0)
// 		return (0);
// 	else
// 		return (1 + ft_list_size_recursive(begin_list->next));
// }

int	ft_list_size(t_list *begin_list)
{
	int result;

	result = 0;
	while (begin_list != NULL){
		result++;
		begin_list = begin_list->next;
	}
	return result;
}

int main(){

	t_list a;
	t_list b;
	t_list c;

	a.next = &b;
	a.data = "aaa";

	b.next = &c;
	b.data = "bbb";

	c.next = '\0';
	c.data = "ccc";

	printf("#1. %d\n",ft_list_size(&a));
	// printf("#2. %d\n",ft_list_size_recursive(&a));

}
