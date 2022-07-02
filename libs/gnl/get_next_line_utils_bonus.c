/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:28:55 by mbesan            #+#    #+#             */
/*   Updated: 2021/10/13 01:38:33 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strnew(size_t size)
{
	char	*a;

	a = (char *)malloc((size + 1) * sizeof(char));
	if (!(a))
		return (NULL);
	return (a);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	size_t	b;
	int		c;

	if (!s1 || !s2)
		return (NULL);
	b = ft_strlen(s1) + ft_strlen(s2);
	a = ft_strnew(b);
	if (!a)
		return (NULL);
	c = 0;
	while (s1[c])
	{
		a[c] = s1[c];
		c++;
	}
	b = 0;
	while (s2[b])
		a[c++] = s2[b++];
	a[c] = '\0';
	return (a);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	a;

	a = 0;
	if (!s)
		return (NULL);
	while (s[a])
	{
		if (s[a] == (char)c)
			return ((char *)(s + a));
		a++;
	}
	if (s[a] == (char)c)
		return ((char *)(s + a));
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t num, size_t size)
{
	size_t	a;
	void	*cal;

	a = 0;
	cal = malloc(num * size);
	if (!cal)
		return (NULL);
	while (a < num * size)
		((unsigned char *)cal)[a++] = '\0';
	return (cal);
}
