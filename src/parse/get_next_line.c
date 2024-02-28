/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:30:22 by sgundogd          #+#    #+#             */
/*   Updated: 2024/02/28 14:53:56 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_read(int fd, char *str)
{
	int		count;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	count = 1;
	while (ft_find_line(str) && (count != 0))
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0)
		{
			free(buffer);
			free(str);
			return (0);
		}
		buffer[count] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(str);
		return (NULL);
	}
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	result = read_line(str);
	str = next_line(str);
	return (result);
}
