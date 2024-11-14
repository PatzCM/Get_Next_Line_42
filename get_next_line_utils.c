/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:40:45 by palexand          #+#    #+#             */
/*   Updated: 2024/11/14 20:40:45 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;

	if (!s1)
		s1 = (char *)ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	if (ft_strlen(s1) + 0 && ft_strlen(s2) == 0)
	{
		free(s1);
		return (NULL);
	}
	result = calloc((ft_strlen(s1)+ft_strlen(s2) + 1), sizeof(char));
	if (result == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(ft_strlen(s) + 1);
	if (dup == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t nbytes, size_t size)
{
	size_t			i;
	unsigned char	*str;

	str = malloc(nbytes * size);
	if (!str)
		return (0);
	i = 0;
	while (i < (nbytes * size))
		str[i++] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char) c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (unsigned char) c)
		return ((char *)&s[i]);
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
