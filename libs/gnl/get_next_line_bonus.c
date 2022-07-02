/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 01:27:58 by mbesan            #+#    #+#             */
/*   Updated: 2021/10/13 01:42:39 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_res_rewrite(char *res, size_t indent)
{
	char	*reres;
	int		x;

	x = 0;
	if (!res[indent])
	{
		free(res);
		return (NULL);
	}
	reres = (char *)ft_calloc((ft_strlen(res) - indent + 1), sizeof(char));
	while (res[indent + 1])
		reres[x++] = res[1 + indent++];
	free(res);
	return (reres);
}

char	*ft_output(char *res, size_t *a_indent)
{
	char	*output;

	if (!res[*(a_indent)])
		return (NULL);
	while (res[(*a_indent)] && res[(*a_indent)] != '\n')
		(*a_indent)++;
	output = (char *)ft_calloc((*a_indent) + 2, sizeof(char));
	*a_indent = 0;
	while (res[(*a_indent)] && res[(*a_indent)] != '\n')
	{
		output[(*a_indent)] = res[(*a_indent)];
		(*a_indent)++;
	}
	if (res[(*a_indent)] == '\n')
		output[(*a_indent)] = '\n';
	return (output);
}

char	*ft_reading(char *res, char *buf, int fd)
{
	int		nread;
	char	*t;

	nread = 1;
	if (!res)
		res = (char *)ft_calloc(1, 1);
	while (nread)
	{
		nread = read(fd, buf, BUFFER_SIZE);
		if (nread < 0)
		{
			free(buf);
			free(res);
			return (NULL);
		}
		buf[nread] = 0;
		t = ft_strjoin(res, buf);
		free(res);
		res = t;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	char		*output;
	static char	*res[MAX_FD];
	size_t		indent;
	char		*buf;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	indent = 0;
	buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	res[fd] = ft_reading(res[fd], buf, fd);
	if (buf)
		free (buf);
	if (!res[fd])
		return (NULL);
	output = ft_output(res[fd], &indent);
	res[fd] = ft_res_rewrite(res[fd], indent);
	return (output);
}
