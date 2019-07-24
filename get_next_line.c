/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:02:18 by mapryl            #+#    #+#             */
/*   Updated: 2019/07/24 15:16:02 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	**add_file(char **stack)
{
	if (*stack == NULL)
		*stack = ft_strnew(0);
	return (stack);
}

static void	new_string(char **stack, char *buffer)
{
	char *temp;

	temp = ft_strjoin(*stack, buffer);
	free(*stack);
	*stack = temp;
}

static int	new_line(char **stack, char **line)
{
	char *temp;

	if ((*stack)[0] == 0)
		return (0);
	if (ft_strchr(*stack, '\n'))
	{
		*(ft_strchr(*stack, '\n')) = '\0';
		*line = ft_strdup(*stack);
		temp = ft_strdup(ft_strchr(*stack, '\0') + 1);
		free(*stack);
		if (temp != 0)
		{
			*stack = ft_strdup(temp);
			free(temp);
		}
	}
	else
	{
		*line = ft_strdup(*stack);
		ft_memdel((void **)stack);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*fd_array[FD_MAX];
	char		buffer[BUFF_SIZE + 1];
	int			counter;

	if (fd <= -1 || line == NULL || fd > FD_MAX || read(fd, buffer, 0) == -1)
		return (-1);
	add_file(&(fd_array[fd]));
	while (!(ft_strchr(fd_array[fd], '\n')))
	{
		counter = read(fd, buffer, BUFF_SIZE);
		buffer[counter] = '\0';
		if (counter == 0)
			break ;
		new_string(&(fd_array[fd]), buffer);
	}
	return (new_line(&(fd_array[fd]), line));
}
