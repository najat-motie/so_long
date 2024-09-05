/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmotie- <nmotie-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:39:18 by nmotie-           #+#    #+#             */
/*   Updated: 2024/09/05 19:26:41 by nmotie-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define LEFT 0
# define RIGHT 2
# define DOWN 1
# define UP 13
# define ESC 53

typedef struct t_position
{
	int		y;
	int		x;
}			t_pos;

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*win;
	void	*floor;
	void	*tree;
	void	*coins;
	void	*door;
	void	*player;
	t_pos	p_pos;
}			t_data;

size_t		ft_strlen(char *s);
char		*ft_strdup(char *s1);
char		*ft_strjoin(char *s1, char *s2);
char		*get_next_line(int fd);
void		check_args(char *str);
char		**read_map(char *file);
int			line_length(char *str);
int			check_letters_of_map(char **map);
int			check_walls(int len, char **map);
int			check_player(t_data *data);
int			check_collectibles(char **map);
int			check_path(char **map);
int			check_exit(char **map);
void		check_errors(int len, t_data *data);
void		extract_images(t_data *img);
void		build_window(t_data *data);
int			key_press(int keycode, t_data *data);
void		double_free(char **map);
void		destroy_images(t_data *data);
int			exit_succes(t_data *data);
int			exit_failure(t_data *data);

#endif