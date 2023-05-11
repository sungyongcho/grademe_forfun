/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sucho <sucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:53:22 by sucho             #+#    #+#             */
/*   Updated: 2023/05/11 23:08:26 by sucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int a = 1;
	int b = 5;

	ft_swap(&a, &b);
	printf("%d\n", a); // should print 5
	printf("%d\n", b); // should print 1

	return 0;
}
