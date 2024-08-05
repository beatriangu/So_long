/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_floodfill.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belamiqu <belamiqu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:21:22 by belamiqu          #+#    #+#             */
/*   Updated: 2023/12/02 19:05:02 by belamiqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_revert_flood_fill(t_map *m)
{
	ft_init_m(m);
	while (m->str[m->i])
	{
		m->j = 0;
		while (m->str[m->i][m->j] != 0)
		{
			if (m->str[m->i][m->j] >= 'P')
				m->str[m->i][m->j] = m->str[m->i][m->j] - 40;
			m->j++;
		}
		m->i++;
	}
}

int	ft_check_flood_fill(t_map *m, int x, int y)
{
	ft_init_m(m);
	if (m->str[x][y] == 'E')
		return (-1);
	while (m->str[m->i])
	{
		m->j = 0;
		while (m->str[m->i][m->j] != 0)
		{
			if (m->str[m->i][m->j] == 'C')
				return (-1);
			m->j++;
		}
		m->i++;
	}
	ft_revert_flood_fill(m);
	return (0);
}

void	ft_flood_fill(t_map *m, int x, int y)
{
	if (m->str[x][y] != '1' && m->str[x][y] <= 'P')
	{
		m->str[x][y] = m->str[x][y] + 40;
		ft_flood_fill(m, x, y + 1);
		ft_flood_fill(m, x, y - 1);
		ft_flood_fill(m, x + 1, y);
		ft_flood_fill(m, x - 1, y);
	}
}

int	ft_checkmap_path_findexit(t_map *m)
{
	ft_init_m(m);
	while (m->str[m->i])
	{
		m->j = 0;
		while (m->str[m->i][m->j] != 'E'
			&& m->str[m->i][m->j] != 0)
			m->j++;
		if (m->str[m->i][m->j] == 'E')
		{
			m->x_exit = m->i;
			m->y_exit = m->j;
		}
		m->i++;
	}
	ft_flood_fill(m, m->player_x, m->player_y);
	return (ft_check_flood_fill(m, m->x_exit, m->y_exit));
}

int	ft_checkmap_path_findpos(t_map *m)
{
	ft_init_m(m);
	while (m->str[m->i])
	{
		m->j = 0;
		while (m->str[m->i][m->j] != 'P'
			&& m->str[m->i][m->j] != 0)
			m->j++;
		if (m->str[m->i][m->j] == 'P')
		{
			m->player_x = m->i;
			m->player_y = m->j;
		}
		m->i++;
	}
	return (ft_checkmap_path_findexit(m));
}
