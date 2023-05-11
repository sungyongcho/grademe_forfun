/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sucho <sucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:47:04 by sucho             #+#    #+#             */
/*   Updated: 2023/05/11 21:54:54 by sucho            ###   ########.fr       */
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

char *ft_strrev(char *s)
{
	char *ret;
	int	len;

	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);

	int i;
	int j;

	i = ft_strlen(s) - 1;
	j = 0;
	while (i >= 0)
	{
		ret[j] = s[i];
		i--;
		j++;
	}
	ret[j] = '\0';

	return ret;
}


int main()
{
	char *hello= "hello";

	printf("%s\n", ft_strrev(hello));
}
