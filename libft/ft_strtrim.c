/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:24:06 by vharkush          #+#    #+#             */
/*   Updated: 2022/10/09 15:24:10 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checkpls(char *set, char a)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == a)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		n;
	int		len;

	i = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen((char *)s1);
	j = len;
	while (checkpls((char *)set, s1[i]) > 0)
		i++;
	while (checkpls((char *)set, s1[j - 1]) > 0)
		j--;
	j = len - j;
	n = len - i - j;
	if (i == len)
		str = malloc(1);
	else
		str = (char *)malloc(sizeof(*s1) * (n + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (n--)
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
