/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:38:31 by nmotie-           #+#    #+#             */
/*   Updated: 2024/09/06 00:04:08 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	extract_images(t_data *data)
{
	int		img_height;
	int		img_width;
	char	*image_path;

	image_path = "./textures/floor.xpm";
	data->floor = mlx_xpm_file_to_image(data->mlx, image_path, &img_width,
			&img_height);
	image_path = "./textures/tree.xpm";
	data->tree = mlx_xpm_file_to_image(data->mlx, image_path, &img_width,
			&img_height);
	image_path = "./textures/player.xpm";
	data->player = mlx_xpm_file_to_image(data->mlx, image_path, &img_width,
			&img_height);
	image_path = "./textures/coins.xpm";
	data->coins = mlx_xpm_file_to_image(data->mlx, image_path, &img_width,
			&img_height);
	image_path = "./textures/door.xpm";
	data->door = mlx_xpm_file_to_image(data->mlx, image_path, &img_width,
			&img_height);
	if (!data->floor || !data->tree || !data->player || !data->coins
		|| !data->door)
	{
		write(1, "The Imge Not Found!\n", 20);
		exit_failure(data);
	}
}

void	put_images(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->tree, j * 50, i
			* 50);
	if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->player, j * 50, i
			* 50);
	if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->coins, j * 50, i
			* 50);
	if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->door, j * 50, i
			* 50);
}

void	build_window(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(data->mlx, data->win);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			mlx_put_image_to_window(data->mlx, data->win, data->floor, j * 50, i
				* 50);
			put_images(data, i, j);
			j++;
		}
		i++;
	}
}
