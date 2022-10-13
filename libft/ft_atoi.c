/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21ft_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:54:55 by vharkush          #+#    #+#             */
/*   Updated: 2022/10/06 18:56:51 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	j;
	int	i;

	i = 0;
	j = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\f')
	{
		i++;
	}
	if ((str[i] == '+' || str[i] == '-') && str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		j = j * 10 + (str[i] - '0');
		i++;
	}
	return (sign * j);
}
