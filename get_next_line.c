#include "get_next_line.h"

static char	*fill_line_buf(int fd, char *left_c, char *buf);
static char	*sep_buffer(char *buf);

char	*burro(char *line)
{
	int	i;
	int d;

	i = 0;
	d = 0;
	while (line[i] && line[i] != '\n')
		i++;
	while (d <= i)
	{
		line[d] = line[d];
		d++;
	}
	line[d] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	char		*buf;
	static char   *left_c;
	
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (read(fd, 0, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buf);
		free(left_c);
		left_c = NULL;
		buf = NULL;
		return (NULL);
	}
	if (!buf)
		return (NULL);
	line = fill_line_buf(fd, left_c, buf); // fill line with the buffer
	free(buf);
	if (!line)
		return (NULL);
	left_c = sep_buffer(line); // separate the buffer
	line = burro(line);
	return (line);
}

static char	*fill_line_buf(int fd, char *left_c, char *buf)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buf, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(left_c);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buf[bytes_read] = 0;
		if (!left_c)
				left_c = ft_strdup("");
		temp = left_c;
		left_c = ft_strjoin(temp, buf);
		free(temp);
}
	return (left_c);
}

static char	*sep_buffer(char *buf)
{
	int		i;
	char	*left_c;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[1] == '\0' || buf[0] == '\0')
		return (NULL);
	left_c = ft_substr(buf, i + 1, ft_strlen(buf) - i);
	buf[i + 1] = '\0';	
	return (left_c);
}

int		main(int ac, char **av)
{
	int		fd;
	
	if (ac != 0)
	{}
	fd = open(av[1], O_RDONLY);
	printf("1) %s", get_next_line(fd));
	printf("2) %s", get_next_line(fd));
	printf("3) %s", get_next_line(fd));
	printf("4) %s", get_next_line(fd));
	printf("5) %s", get_next_line(fd));
	printf("6) %s", get_next_line(fd));
	printf("7) %s", get_next_line(fd));
	return (0);
}
