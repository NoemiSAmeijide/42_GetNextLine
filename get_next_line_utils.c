/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:54:50 by nosilves          #+#    #+#             */
/*   Updated: 2023/08/27 21:57:30 by nosilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strdub(char *s1)
{
	size_t	len;
	char	*s2;
	size_t	i;

	i = -1;
	len = ft_strlen(s1) + 1;
	s2 = malloc(len);
	if (!s2)
		return (NULL);
	while (++i < len)
		s2[i] = s1[i];
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	slen1;
	size_t	slen2;
	size_t	i;

	if (!s1)
		return (ft_strdub(s2));
	i = -1;
	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	ptr = malloc ((slen1 + slen2 + 1) * sizeof(char));
	if (!ptr)
	{
		free (s1);
		return (NULL);
	}
	while (++i < slen1)
		ptr[i] = s1[i];
	i = -1;
	while (++i < slen2)
		ptr[i + slen1] = s2[i];
	ptr[i + slen1] = '\0';
	free (s1);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s != (char)c)
		return ((char *)0);
	return ((char *)s);
}
