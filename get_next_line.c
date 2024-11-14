/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:38:58 by palexand          #+#    #+#             */
/*   Updated: 2024/11/14 20:38:58 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_line(int fd, char *left_c, char *buf);
static char	*sep_buffer(char *buf);

char	*burro(char *buf)
{
	int	i;
	int	d;
	char	*line;
	i = 0;
	d = 0;
	
	while (buf[i] && buf[i] != '\n')
		i++;
	line = (char *)calloc((i + 2), sizeof(char));
	if (!line)
	{
		free(buf);
		return (NULL);
	}
	while (d <= i)
	{
		line[d] = buf[d];
		d++;
	}
	line[d] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char					*line;
	char					*buf;
	static char				*left_c;

	buf = (char *)calloc((BUFFER_SIZE + 1), sizeof(char));
	if (read(fd, 0, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0 )
	{
		free(buf);
		free(left_c);
		left_c = NULL;
		buf = NULL;
		return (NULL);
	}
	if (!buf)
		return (NULL);
	line = fill_line(fd, left_c, buf);
	free(buf);
	if (!line)
		return (NULL);
	left_c = sep_buffer(line);
	line = burro(line);
	return (line);
}

static char	*fill_line(int fd, char *left_c, char *buf)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buf, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
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
		temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (left_c);
}

static char	*sep_buffer(char *buf)
{
	int		i;
	int		j;
	char	*left_c;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[1] == '\0' || buf[0] == '\0')
		return (NULL);
	left_c = ft_calloc((ft_strlen(buf) -i + 1), sizeof(char));
	if (!left_c)
		return (NULL);
	j = 0;
	while (buf[i++] != '\0')
		left_c[j++] = buf[i];
	left_c[j] = '\0';
	return (left_c);
}

int		main(int ac, char **av)
{
	int		fd;

	if (ac != 0)
	{
	}
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
