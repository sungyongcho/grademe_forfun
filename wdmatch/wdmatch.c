/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sucho <sucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:03:13 by sucho             #+#    #+#             */
/*   Updated: 2023/05/14 23:05:29 by sucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}


int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		int i;
		int counter = 0;

		i = 0;
		while (argv[2][i])
		{
			if (argv[2][i] == argv[1][counter])
			{
				counter++;
			}
			i++;
		}
		// printf("argv[1]:%s\nargv[2]:%s\n", argv[1], argv[2]);
		// printf("counter:%d\targv[1] len: %d\n", counter, ft_strlen(argv[1]));
		// printf("result:%d\n", result);
		if (ft_strlen(argv[1]) == counter)
			printf("%s", argv[1]);
		printf("\n");
	}
	else
		printf("\n");
	return (0);
}

// ex1.
// $>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e

