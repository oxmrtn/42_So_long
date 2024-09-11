/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opps_movements_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:32:31 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/03 16:17:02 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs_bonus/so_long_bonus.h"

int	opps_turn(t_Game *game)
{
	int	i;
	int	rdm;
	int	end;

	end = 0;
	i = 0;
	if (!game->opps_list)
		return (0);
	while (game->opps_list[i])
	{
		rdm = ft_random(1, 4);
		if (rdm == 1)
			end += ops_movements_w(game, game->opps_list[i]);
		else if (rdm == 2)
			end += ops_movements_a(game, game->opps_list[i]);
		else if (rdm == 3)
			end += ops_movements_s(game, game->opps_list[i]);
		else
			end += ops_movements_d(game, game->opps_list[i]);
		i++;
	}
	return (end);
}

int	ops_movements_w(t_Game *game, t_Opps *ops)
{
	const int	x = ops->x;
	const int	y = ops->y;
	const char	tmp = game->map[x - 1][y];

	if (tmp == '1' || tmp == 'E' || tmp == 'C' || tmp == 'O')
		return (0);
	if (game->map[x - 1][y] == 'P')
	{
		game->player->w = 2;
		render_opps_d(game, ops, x, y);
		mlx_loop_end(game->d.mlx);
		return (1);
	}
	else
	{
		game->map[x][y] = '0';
		game->map[x - 1][y] = 'O';
		ops->x = x - 1;
		render_opps_w(game, ops, x, y);
	}
	return (0);
}

int	ops_movements_s(t_Game *game, t_Opps *ops)
{
	const int	x = ops->x;
	const int	y = ops->y;
	const char	tmp = game->map[x + 1][y];

	if (tmp == '1' || tmp == 'E' || tmp == 'C' || tmp == 'O')
		return (0);
	if (game->map[x + 1][y] == 'P')
	{
		game->player->w = 2;
		render_opps_d(game, ops, x, y);
		mlx_loop_end(game->d.mlx);
		return (1);
	}
	else
	{
		game->map[x][y] = '0';
		game->map[x + 1][y] = 'O';
		ops->x = x + 1;
		render_opps_s(game, ops, x, y);
	}
	return (0);
}

int	ops_movements_a(t_Game *game, t_Opps *ops)
{
	const int	x = ops->x;
	const int	y = ops->y;
	const char	tmp = game->map[x][y - 1];

	if (tmp == '1' || tmp == 'E' || tmp == 'C' || tmp == 'O')
		return (0);
	if (game->map[x][y - 1] == 'P')
	{
		game->player->w = 2;
		render_opps_d(game, ops, x, y);
		mlx_loop_end(game->d.mlx);
		return (1);
	}
	else
	{
		game->map[x][y] = '0';
		game->map[x][y - 1] = 'O';
		ops->y = y - 1;
		render_opps_a(game, ops, x, y);
	}
	return (0);
}

int	ops_movements_d(t_Game *game, t_Opps *ops)
{
	const int	x = ops->x;
	const int	y = ops->y;
	const char	tmp = game->map[x][y + 1];

	if (tmp == '1' || tmp == 'E' || tmp == 'C' || tmp == 'O')
		return (0);
	if (game->map[x][y + 1] == 'P')
	{
		game->player->w = 2;
		render_opps_d(game, ops, x, y);
		mlx_loop_end(game->d.mlx);
		return (1);
	}
	else
	{
		game->map[x][y] = '0';
		game->map[x][y + 1] = 'O';
		ops->y = y + 1;
		render_opps_d(game, ops, x, y);
	}
	return (0);
}
