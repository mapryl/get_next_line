#include "get_next_line.h"
#include <stdio.h>
int main(void)
{
	int fd;
	if (_sopen_s(&fd, "1.txt", _O_RDONLY, _SH_DENYNO, 0))
	{
		printf("error");
		return -1;
	}
	char *line;
	while (get_next_line(fd, &line))
	{
		printf("%s", line);
	}
	return 0;
}