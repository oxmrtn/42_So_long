/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:15:02 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/03 15:55:52 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs_bonus/so_long_bonus.h"

static void	bis(void *mlx, void *win, void *img, t_nk nk)
{
	mlx_put_image_to_window(mlx, win, img, nk.j * 64, nk.i * 64);
}

void	render_third(t_Game *game, t_nk nk)
{
	if (game->map[nk.i][nk.j] == '1')
		bis(game->d.mlx, game->d.mlx_win, game->t->wal, nk);
	else if (game->map[nk.i][nk.j] == 'C')
		bis(game->d.mlx, game->d.mlx_win, game->t->col, nk);
	else if (game->map[nk.i][nk.j] == 'P')
		bis(game->d.mlx, game->d.mlx_win, game->t->p_1s, nk);
	else if (game->map[nk.i][nk.j] == 'E' && game->exit->is_open)
		bis(game->d.mlx, game->d.mlx_win, game->t->o_e, nk);
	else if (game->map[nk.i][nk.j] == 'E' && !game->exit->is_open)
		bis(game->d.mlx, game->d.mlx_win, game->t->c_e, nk);
	else if (game->map[nk.i][nk.j] == 'O')
		bis(game->d.mlx, game->d.mlx_win, game->t->o_s, nk);
	else
		bis(game->d.mlx, game->d.mlx_win, game->t->til, nk);
}

void	render_second(t_Game *game, t_nk nk)
{
	if (nk.i == 0)
	{
		if (nk.j == 0)
			bis(game->d.mlx, game->d.mlx_win, game->t->tl_c, nk);
		else if (!game->map[nk.i][nk.j + 1])
			bis(game->d.mlx, game->d.mlx_win, game->t->tr_c, nk);
		else
			bis(game->d.mlx, game->d.mlx_win, game->t->w_u, nk);
	}
	else if (nk.j == 0 && game->map[nk.i + 1])
		bis(game->d.mlx, game->d.mlx_win, game->t->w_r, nk);
	else if (!game->map[nk.i][nk.j + 1] && game->map[nk.i + 1])
		bis(game->d.mlx, game->d.mlx_win, game->t->w_l, nk);
	else if (!game->map[nk.i + 1])
	{
		if (nk.j == 0)
			bis(game->d.mlx, game->d.mlx_win, game->t->bl_c, nk);
		else if (!game->map[nk.i][nk.j + 1])
			bis(game->d.mlx, game->d.mlx_win, game->t->br_c, nk);
		else
			bis(game->d.mlx, game->d.mlx_win, game->t->w_b, nk);
	}
	else
		render_third(game, nk);
}

void	render_map(t_Game *game)
{
	t_nk	nk;

	nk.i = 0;
	while (game->map[nk.i])
	{
		nk.j = 0;
		while (game->map[nk.i][nk.j])
		{
			render_second(game, nk);
			nk.j ++;
		}
		nk.i++;
	}
}
