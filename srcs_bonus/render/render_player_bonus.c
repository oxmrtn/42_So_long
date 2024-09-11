/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:47:16 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/03 16:17:57 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs_bonus/so_long_bonus.h"

static void	bis(void *mlx, void *win, void *img, t_nk nk)
{
	mlx_put_image_to_window(mlx, win, img, nk.j * 64, nk.i * 64);
}

void	render_player_w(t_Game *game, int px, int py)
{
	t_nk	nk;
	t_nk	nk2;

	nk.i = px;
	nk.j = py;
	nk2.i = game->player->x;
	nk2.j = game->player->y;
	bis(game->d.mlx, game->d.mlx_win, game->t->til, nk);
	if (game->player->lvl == 0)
		bis(game->d.mlx, game->d.mlx_win, game->t->p_1w, nk2);
	else if (game->player->lvl == 1)
		bis(game->d.mlx, game->d.mlx_win, game->t->p_2w, nk2);
	else if (game->player->lvl >= 2)
		bis(game->d.mlx, game->d.mlx_win, game->t->p_3w, nk2);
	if (game->exit->is_open)
	{
		nk.i = game->exit->x;
		nk.j = game->exit->y;
		bis(game->d.mlx, game->d.mlx_win, game->t->o_e, nk);
	}
	render_moovs(game);
}

void	render_player_a(t_Game *game, int px, int py)
{
	t_nk	nk;
	t_nk	nk2;

	nk.i = px;
	nk.j = py;
	nk2.i = game->player->x;
	nk2.j = game->player->y;
	bis(game->d.mlx, game->d.mlx_win, game->t->til, nk);
	if (game->player->lvl == 0)
		bis(game->d.mlx, game->d.mlx_win, game->t->p_1a, nk2);
	else if (game->player->lvl == 1)
		bis(game->d.mlx, game->d.mlx_win, game->t->p_2a, nk2);
	else if (game->player->lvl >= 2)
		bis(game->d.mlx, game->d.mlx_win, game->t->p_3a, nk2);
	if (game->exit->is_open)
	{
		nk.i = game->exit->x;
		nk.j = game->exit->y;
		bis(game->d.mlx, game->d.mlx_win, game->t->o_e, nk);
	}
	render_moovs(game);
}

void	render_player_s(t_Game *game, int px, int py)
{
	t_nk	nk;
	t_nk	nk2;

	nk.i = px;
	nk.j = py;
	nk2.i = game->player->x;
	nk2.j = game->player->y;
	bis(game->d.mlx, game->d.mlx_win, game->t->til, nk);
	if (game->player->lvl == 0)
		bis(game->d.mlx, game->d.mlx_win, game->t->p_1s, nk2);
	else if (game->player->lvl == 1)
		bis(game->d.mlx, game->d.mlx_win, game->t->p_2s, nk2);
	else if (game->player->lvl >= 2)
		bis(game->d.mlx, game->d.mlx_win, game->t->p_3s, nk2);
	if (game->exit->is_open)
	{
		nk.i = game->exit->x;
		nk.j = game->exit->y;
		bis(game->d.mlx, game->d.mlx_win, game->t->o_e, nk);
	}
	render_moovs(game);
}

void	render_player_d(t_Game *game, int px, int py)
{
	t_nk	nk;
	t_nk	nk2;

	nk.i = px;
	nk.j = py;
	nk2.i = game->player->x;
	nk2.j = game->player->y;
	bis(game->d.mlx, game->d.mlx_win, game->t->til, nk);
	if (game->player->lvl == 0)
		bis(game->d.mlx, game->d.mlx_win, game->t->p_1d, nk2);
	else if (game->player->lvl == 1)
		bis(game->d.mlx, game->d.mlx_win, game->t->p_2d, nk2);
	else if (game->player->lvl >= 2)
		bis(game->d.mlx, game->d.mlx_win, game->t->p_3d, nk2);
	if (game->exit->is_open)
	{
		nk.i = game->exit->x;
		nk.j = game->exit->y;
		bis(game->d.mlx, game->d.mlx_win, game->t->o_e, nk);
	}
	render_moovs(game);
}
