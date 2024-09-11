/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:21:10 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/03 16:44:59 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs_bonus/so_long_bonus.h"

void	ft_move_w(t_Game *game)
{
	const int	x = game->player->x;
	const int	y = game->player->y;
	const char	tmp = game->map[x - 1][y];

	if (x - 1 < 0 || tmp == '1' || (tmp == 'E' && !game->exit->is_open))
		return ;
	if (tmp == 'E' && game->exit->is_open)
	{
		game->player->w = 1;
		mlx_loop_end(game->d.mlx);
	}
	if (tmp == 'O')
		mlx_loop_end(game->d.mlx);
	else
	{
		game->map[x][y] = '0';
		if (game->map[x - 1][y] == 'C')
			eat_collectible(x - 1, y, game);
		game->map[x - 1][y] = 'P';
		game->player->x = x - 1;
		game->moov++;
		render_player_w(game, x, y);
	}
}

void	ft_move_s(t_Game *game)
{
	const int	x = game->player->x;
	const int	y = game->player->y;
	const char	tmp = game->map[x + 1][y];

	if (x + 1 < 0 || tmp == '1' || (tmp == 'E' && !game->exit->is_open))
		return ;
	if (tmp == 'E' && game->exit->is_open)
	{
		game->player->w = 1;
		mlx_loop_end(game->d.mlx);
	}
	if (tmp == 'O')
		mlx_loop_end(game->d.mlx);
	else
	{
		game->map[x][y] = '0';
		if (game->map[x + 1][y] == 'C')
			eat_collectible(x + 1, y, game);
		game->map[x + 1][y] = 'P';
		game->player->x = x + 1;
		game->moov++;
		render_player_s(game, x, y);
	}
}

void	ft_move_a(t_Game *game)
{
	const int	x = game->player->x;
	const int	y = game->player->y;
	const char	tmp = game->map[x][y - 1];

	if (y - 1 < 0 || tmp == '1' || (tmp == 'E' && !game->exit->is_open))
		return ;
	if (tmp == 'E' && game->exit->is_open)
	{
		game->player->w = 1;
		mlx_loop_end(game->d.mlx);
	}
	if (tmp == 'O')
		mlx_loop_end(game->d.mlx);
	else
	{
		game->map[x][y] = '0';
		if (game->map[x][y - 1] == 'C')
			eat_collectible(x, y - 1, game);
		game->map[x][y - 1] = 'P';
		game->player->y = y - 1;
		game->moov++;
		render_player_a(game, x, y);
	}
}

void	ft_move_d(t_Game *game)
{
	const int	x = game->player->x;
	const int	y = game->player->y;
	const char	tmp = game->map[x][y + 1];

	if (y + 1 < 0 || tmp == '1' || (tmp == 'E' && !game->exit->is_open))
		return ;
	if (tmp == 'E' && game->exit->is_open)
	{
		game->player->w = 1;
		mlx_loop_end(game->d.mlx);
	}
	if (tmp == 'O')
		mlx_loop_end(game->d.mlx);
	else
	{
		game->map[x][y] = '0';
		if (game->map[x][y + 1] == 'C')
			eat_collectible(x, y + 1, game);
		game->map[x][y + 1] = 'P';
		game->player->y = y + 1;
		game->moov++;
		render_player_d(game, x, y);
	}
}
