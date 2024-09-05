/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:38:27 by nmotie-           #+#    #+#             */
/*   Updated: 2024/09/05 23:51:59 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	length_map(char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(1, "File Not Exist!\n", 16);
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

char	**read_map(char *file)
{
	int		i;
	int		len;
	int		fd;
	char	*line;
	char	**map;

	i = 0;
	len = length_map(file);
	fd = open(file, O_RDONLY);
	map = malloc((len + 1) * sizeof(char *));
	if (map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map[i] = line;
		i++;
	}
	close(fd);
	map[i] = NULL;
	return (map);
}
