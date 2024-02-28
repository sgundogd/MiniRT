/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:30:25 by sgundogd          #+#    #+#             */
/*   Updated: 2024/02/28 14:53:33 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

int	ft_find_line(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (*str == '\n')
			return (0);
		str++;
	}
	return (1);
}

char	*ft_strjoin(char *str, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = -1;
	j = 0;
	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	result = malloc(sizeof(char) * ft_strlen(str) + ft_strlen(buffer) + 1);
	if (!result)
		return (NULL);
	while (str[++i])
		result[i] = str[i];
	while (buffer[j])
		result[i++] = buffer[j++];
	free(str);
	result[i] = '\0';
	return (result);
}

char	*read_line(char *str)
{
	size_t	i;
	char	*result;

	i = 0;
	if (!*str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	result = malloc(i + 2);
	if (!result)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		result[i] = str[i];
	if (str[i] == '\n')
		result[i++] = '\n';
	result[i] = '\0';
	return (result);
}

char	*next_line(char *str)
{
	int		i;
	char	*result;
	int		j;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!*str)
	{
		free(str);
		return (NULL);
	}
	if (str[i] == '\n')
		i++;
	result = malloc(ft_strlen(str) - i + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}
