#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//# include <unistd.h>
#include <io.h>
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>

# define BUFF_SIZE 32
# define FD_MAX 10240

int	get_next_line(const int fd, char **line);

#endif