/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgundogd <sgundogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:54:16 by sgundogd          #+#    #+#             */
/*   Updated: 2024/02/28 14:54:17 by sgundogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
int		ft_find_line(char *str);
char	*ft_strjoin(char *str, char	*buffer);
char	*next_line(char *str);
char	*read_line(char	*str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
#endif
