/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:10:11 by sgundogd          #+#    #+#             */
/*   Updated: 2024/02/28 18:41:10 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static int	control_atod(const char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.'
			&& str[i] != '-' && str[i] != '+')
			return (0);
		else if (str[i] == '.')
		{
			counter++;
			if (str[i + 1] && !(str [i + 1] >= '0' || str [i + 1] <= '9'))
				return (0);
		}
		else if (str[i + 1] && (str[i + 1] == '+' || str [i + 1] == '-'))
			return (0);
		i++;
	}
	if (counter > 1)
		return (0);
	return (1);
}


double	ft_atod(const char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		infraction;

	result = 0;
	fraction = 1.0;
	sign = 1;
	infraction = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	if (!control_atod(str))
		return (INFINITY);
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			result = result * 10.0 + (*str - '0');
			if (infraction)
				fraction *= 10.0;
		}
		else if (*str == '.')
			infraction = 1;
		else
			break ;
		str++;
	}
	result = sign * result / fraction;
	return (result);
}
