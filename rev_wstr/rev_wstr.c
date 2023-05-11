/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sucho <sucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:03:13 by sucho             #+#    #+#             */
/*   Updated: 2023/05/11 22:46:01 by sucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_spacelen(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
		{
			// i++;
			break;
		}
		i++;
	}
	return i;
}

int	count_space(char *s)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			ret++;
		i++;
	}
	return ret;
}

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		printf("%d\n", count_space(argv[1]));
		// do you know why +1 +1 rather +2?
		char **ret = (char **)malloc(sizeof(char *) * (count_space(argv[1]) + 1 + 1));

		int i;
		int j;
		int save;

		i = 0;
		save = 0;
		while (i < (count_space(argv[1]) + 1))
		{
			// printf("argv: %s spacelen: %d\n", argv[1] + save, ft_spacelen(argv[1] + save));
			ret[i] = (char *)malloc(sizeof(char) * ft_spacelen(argv[1] + save));

			j = 0;
			while (j < ft_spacelen((argv[1] + save)))
			{
				ret[i][j] = argv[1][j + save];
				j++;
			}
			save += (ft_spacelen(argv[1] + save) + 1);
			ret[i][j] = '\0';
			// printf("%s\n", ret[i]);
			i++;
		}
		ret[i] = NULL;

		i = count_space(argv[1]);
		while (i >= 0)
		{
			printf("%s", ret[i]);
			i--;
			if (i == 0)
				;
			else
				printf(" ");
		}

	}
	else
		printf("\n");
	return (0);
}
