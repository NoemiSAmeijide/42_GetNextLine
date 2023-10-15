/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 22:00:42 by nosilves          #+#    #+#             */
/*   Updated: 2023/08/27 22:11:52 by nosilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*fill_storage(int fd, char *storage)
{
	char	*buffer;
	int		numbites;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free (storage);
		return (NULL);
	}
	buffer[0] = '\0';
	numbites = 1;
	while (!ft_strchr(buffer, '\n') && numbites > 0)
	{
		numbites = read(fd, buffer, BUFFER_SIZE);
		if (numbites == -1)
		{
			free (buffer);
			free (storage);
			return (NULL);
		}
		buffer[numbites] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free (buffer);
	return (storage);
}

char	*extract_line(char *storage, int i, int j)
{
	char	*linea;

	if (storage[i] == '\0')
		return (NULL);
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	linea = malloc(sizeof(char) * (i + 1));
	if (!linea)
		return (NULL);
	while (storage[j] != '\0' && storage[j] != '\n')
	{
		linea[j] = storage[j];
		j++;
	}
	if (storage[j] == '\n')
	{
		linea[j] = storage[j];
		j++;
	}
	linea[j] = '\0';
	return (linea);
}

char	*ft_free_them_all(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

char	*clean_storage(char *storage)
{
	int		i;
	int		j;
	char	*new_storage;

	i = 0;
	j = -1;
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (storage[i] == '\0')
		return (ft_free_them_all(&storage));
	i++;
	new_storage = malloc(sizeof(char) * (ft_strlen(storage) - i + 1));
	if (!new_storage)
		return (ft_free_them_all(&storage));
	while (storage[i + ++j] != '\0')
		new_storage[j] = storage[i + j];
	if (j == 0)
	{
		free (new_storage);
		return (ft_free_them_all(&storage));
	}
	new_storage[j] = '\0';
	free (storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024] = {0};
	char		*linea;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage[fd] = fill_storage(fd, storage[fd]);
	if (storage[fd] == NULL)
		return (NULL);
	linea = extract_line(storage[fd], 0, 0);
	if (linea == NULL)
	{
		free (storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	storage[fd] = clean_storage(storage[fd]);
	return (linea);
}
