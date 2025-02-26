/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onevilx <onevilx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:11:12 by onevilx           #+#    #+#             */
/*   Updated: 2025/02/26 22:11:14 by onevilx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	char	*dst;
	int		i = 0;
	while(src[i])
		i++;
	dst = malloc(i + 1);
	i = -1;
	while(src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buffer_readed;
	static int	buffer_posi;
	char		line[70000];
	int			i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_posi >= buffer_readed)
		{
			buffer_readed = read(fd, buffer, BUFFER_SIZE);
			buffer_posi = 0;
			if (buffer_readed <= 0)
				break ;
		}
		line[i++] = buffer[buffer_posi++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return(ft_strdup(line));
}
