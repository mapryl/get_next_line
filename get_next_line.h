/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:12:18 by mapryl            #+#    #+#             */
/*   Updated: 2019/07/24 15:22:00 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "libft/includes/libft.h"
# include <fcntl.h>
# include <stdlib.h>

# define BUFF_SIZE 32
# define FD_MAX 10240

int	get_next_line(const int fd, char **line);

#endif
