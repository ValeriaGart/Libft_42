/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:20:51 by vharkush          #+#    #+#             */
/*   Updated: 2022/10/11 10:21:03 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] == c && s[j + 1] != '\0' && s[j] != s[0])
		{
			while (s[j] == c)
				j++;
			i++;
		}
		if (s[j] != '\0')
			j++;
	}
	if (i > 0 && s[j - 1] == c && s[j - 2] == c)
		return (i);
	return (i + 1);
}

int	word_index(int word, char c, char *s)
{
	int	i;

	i = 0;
	while (word--)
	{
		while (s[i] != c)
			i++;
		while (s[i] == c)
			i++;
	}
	return (i);
}

void	*assign_pls(char *s, char c, int word)
{
	int		i;
	int		length;
	char	*res;

	i = 0;
	if (word != 0)
		i = word_index(word, c, (char *)s);
	length = i;
	while (s[length] != c && s[length] != '\0')
		length++;
	length -= i;
	res = malloc(sizeof(char *) * (length + 1));
	if (!res)
		return (0);
	res[length] = '\0';
	length = 0;
	while (s[i] != c && s[i] != '\0')
	{
		res[length] = s[i];
		i++;
		length++;
	}
	return ((char *)res);
}

void	res_ass(char *str, char c, char **res, int words)
{
	int	i;

	i = 0;
	while (words--)
	{
		res[i] = assign_pls(str, c, i);
		i++;
	}
	res[i] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**res;
	int		words;

	if (!s)
		return (0);
	if (s[0] == '\0')
	{
		res = malloc(1);
		res[0] = '\0';
		return (res);
	}
	str = (char *)s;
	while (*str == c)
		str++;
	words = count_words(str, c);
	res = (char **)malloc(sizeof(char **) * (words + 1));
	if (!res)
		return (NULL);
	res_ass(str, c, res, words);
	return (res);
}
