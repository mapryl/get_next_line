#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include <fcntl.h>
#include <io.h>

typedef char* string_iterator;
typedef struct {
	int size;
	string_iterator begin;
	string_iterator end;
} string;

string string_create(string_iterator begin, string_iterator end)
{
	string str;
	str.size = end - begin;
	str.begin = (string_iterator) malloc(sizeof(char)*str.size);

	string_iterator dst = str.begin;
	for (string_iterator src = begin; src != end; ++src, ++dst)
	{
		*dst = *src;
	}
	str.end = dst;
	return str;
}

void string_delete(string* s)
{
	free(s->begin);
	s->begin = NULL;
	s->end = NULL;
	s->size = 0;
}

void string_append(string *s, string_iterator begin, string_iterator end)
{
	string str;
	str.size = s->size + end - begin;
	str.begin = malloc(str.size);

	memcpy(str.begin, s->begin, s->size);
	memcpy(str.begin + s->size, begin, end - begin);

	str.end = str.begin + str.size;

	string_delete(s);

	*s = str;
}

string_iterator string_find(string s, char ch)
{
	for (string_iterator it = s.begin; it != s.end; ++it)
	{
		if (*it == ch)
			return it;
	}
	return s.end;
}

char* string_c_str(string_iterator begin, string_iterator end)
{
	int size = end - begin;
	char* c_str = malloc(size + 1);
	memcpy(c_str, begin, size);
	c_str[size] = '\0';
	return c_str;
}

#define FD_MAX 10
#define BUFF_SIZE 20

int			get_next_line(const int fd, char** line)
{
	static string stack[FD_MAX];
	char		buf[BUFF_SIZE + 1];
	int			count;
	string_iterator it;

	if (fd <= -1 || line == NULL || fd > FD_MAX || _read(fd, buf, 0) == -1)
		return (-1);

	while ((it = string_find(stack[fd], '\n')) == stack[fd].end)
	{
		count = _read(fd, buf, BUFF_SIZE);
		if (!count)
		{
			*line = string_c_str(stack[fd].begin, stack[fd].end);
			string_delete(&stack[fd]);
			return **line != '\0';
		}
		string_append(&stack[fd], buf, buf + count);
	}
	string tmp = string_create(it + 1, stack[fd].end);
	*line = string_c_str(stack[fd].begin, it);

	string_delete(&stack[fd]);
	string_append(&stack[fd], tmp.begin, tmp.end);

	string_delete(&tmp);
	return 1;
}

int main(void)
{
	int fd;
	if (_sopen_s(&fd, "ConsoleApplication1.c", _O_RDONLY, _SH_DENYNO, 0))
	{
		printf("error");
		return -1;
	}
	char* line;
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
	}
	return 0;
}