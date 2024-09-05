/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:39:04 by nmotie-           #+#    #+#             */
/*   Updated: 2024/09/05 23:38:12 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**double_dup(char **map)
{
	int		i;
	char	**map_copy;

	i = 0;
	while (map[i] != NULL)
		i++;
	map_copy = malloc((i + 1) * sizeof(char *));
	if (map_copy == NULL)
		return (NULL);
	i = 0;
	while (map && map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

int	fill_map(char **map_copy, int status, int i, int j)
{
	if (map_copy[i][j - 1] != '1' && map_copy[i][j - 1] != 'P' && map_copy[i][j
		- 1] != 'E')
	{
		map_copy[i][j - 1] = 'P';
		status = 1;
	}
	if (map_copy[i][j + 1] != '1' && map_copy[i][j + 1] != 'P' && map_copy[i][j
		+ 1] != 'E')
	{
		map_copy[i][j + 1] = 'P';
		status = 1;
	}
	if (map_copy[i - 1][j] != '1' && map_copy[i - 1][j] != 'P' && map_copy[i
		- 1][j] != 'E')
	{
		map_copy[i - 1][j] = 'P';
		status = 1;
	}
	if (map_copy[i + 1][j] != '1' && map_copy[i + 1][j] != 'P' && map_copy[i
		+ 1][j] != 'E')
	{
		map_copy[i + 1][j] = 'P';
		status = 1;
	}
	return (status);
}

int	find_path(char **map_copy, int status, int i, int j)
{
	while (map_copy[i])
	{
		j = 1;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'P')
				status = fill_map(map_copy, status, i, j);
			j++;
		}
		i++;
		if (map_copy[i] == NULL && status == 1)
		{
			i = 1;
			j = 1;
			status = 0;
		}
	}
	return (0);
}

int	door_arrived(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				if (map[i + 1][j] == 'P' || map[i - 1][j] == 'P' || map[i][j
					+ 1] == 'P' || map[i][j - 1] == 'P')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_path(char **map)
{
	int		i;
	int		j;
	int		status;
	char	**map_copy;

	i = 1;
	j = 1;
	status = 0;
	map_copy = double_dup(map);
	if (find_path(map_copy, status, i, j) || !check_collectibles(map_copy)
		|| door_arrived(map_copy))
	{
		double_free(map_copy);
		return (1);
	}
	else
	{
		double_free(map_copy);
		return (0);
	}
}
