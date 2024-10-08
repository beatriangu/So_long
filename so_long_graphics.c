/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_graphics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belamiqu <belamiqu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:35:10 by belamiqu          #+#    #+#             */
/*   Updated: 2023/12/07 20:07:12 by belamiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keyhook(int keycode, t_map *m)
{
	ft_init_m(m);
	if (keycode == 53)
		exit(0);
	if (keycode == 2 || keycode == 124)
		if (m->str[m->player_x][m->player_y + 1] != 1)
			ft_move_right(m);
	if (keycode == 1 || keycode == 125)
		if (m->str[m->player_x + 1][m->player_y] != 1)
			ft_move_down(m);
	if (keycode == 0 || keycode == 123)
		if (m->str[m->player_x][m->player_y - 1] != 1)
			ft_move_left(m);
	if (keycode == 13 || keycode == 126)
		if (m->str[m->player_x - 1][m->player_y] != 1)
			ft_move_up(m);
	mlx_clear_window(m->mlx, m->window);
	ft_render_window(m);
	return (0);
}

int	ft_exit_rb(t_map *m)
{
	mlx_destroy_window(m->mlx, m->window);
	free(m->str);
	free(m->map);
	exit (0);
}

void	ft_put_image_window(t_map *m)
{
	if (m->str[m->i][m->j] == '1')
		mlx_put_image_to_window(m->mlx, m->window, m->tree,
			m->y, m->c);
	else if (m->str[m->i][m->j] == '0')
		mlx_put_image_to_window(m->mlx, m->window, m->snow,
			m->y, m->c);
	else if (m->str[m->i][m->j] == 'C')
		mlx_put_image_to_window(m->mlx, m->window, m->bird,
			m->y, m->c);
	else if (m->str[m->i][m->j] == 'P')
		mlx_put_image_to_window(m->mlx, m->window, m->snoopy,
			m->y, m->c);
	else if (m->str[m->i][m->j] == 'E')
		mlx_put_image_to_window(m->mlx, m->window, m->house,
			m->y, m->c);
}

void	ft_render_window(t_map *m)
{
	ft_init_m(m);
	m->c = -50;
	while (m->str[m->i])
	{
		m->j = 0;
		m->c = m->c + 50;
		m->y = 0;
		while (m->str[m->i][m->j])
		{
			ft_put_image_window(m);
			m->y = m->y + 50;
			m->j++;
		}
		m->i++;
	}
}

void	ft_start_window(t_map *m)
{
	m->mlx = mlx_init();
	m->img_width = 50;
	m->img_height = 50;
	m->window = mlx_new_window(m->mlx, m->img_width * m->width,
			m->img_height * m->num_lines, "SO_LONG");
	m->house = mlx_xpm_file_to_image(m->mlx, "./textures/exit.xpm",
			&m->img_width, &m->img_height);
	m->snow = mlx_xpm_file_to_image(m->mlx, "./textures/floor.xpm",
			&m->img_width, &m->img_height);
	m->bird = mlx_xpm_file_to_image(m->mlx, "./textures/coin.xpm",
			&m->img_width, &m->img_height);
	m->snoopy = mlx_xpm_file_to_image(m->mlx, "./textures/player.xpm",
			&m->img_width, &m->img_height);
	m->tree = mlx_xpm_file_to_image(m->mlx, "./textures/wall.xpm",
			&m->img_width, &m->img_height);
	ft_render_window(m);
}
