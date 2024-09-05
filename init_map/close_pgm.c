/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pgm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:44:15 by nmotie-           #+#    #+#             */
/*   Updated: 2024/09/05 22:50:13 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	double_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	destroy_images(t_data *data)
{
	if (data->floor)
		mlx_destroy_image(data->mlx, data->floor);
	if (data->tree)
		mlx_destroy_image(data->mlx, data->tree);
	if (data->coins)
		mlx_destroy_image(data->mlx, data->coins);
	if (data->door)
		mlx_destroy_image(data->mlx, data->door);
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
}

int	exit_succes(t_data *data)
{
	destroy_images(data);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	double_free(data->map);
	write (1, "Game Over!\n", 11);
	exit(0);
	return (0);
}

int	exit_failure(t_data *data)
{
	destroy_images(data);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	double_free(data->map);
	exit(1);
	return (0);
}
