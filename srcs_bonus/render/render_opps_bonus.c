/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_opps_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:27:57 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/03 16:18:42 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs_bonus/so_long_bonus.h"

static void	bis(void *mlx, void *win, void *img, t_nk nk)
{
	mlx_put_image_to_window(mlx, win, img, nk.j * 64, nk.i * 64);
}

void	render_opps_w(t_Game *game, t_Opps *ops, int ox, int oy)
{
	t_nk	nk;
	t_nk	nk2;

	nk.i = ox;
	nk.j = oy;
	nk2.i = ops->x;
	nk2.j = ops->y;
	bis(game->d.mlx, game->d.mlx_win, game->t->til, nk);
	bis(game->d.mlx, game->d.mlx_win, game->t->o_w, nk2);
}

void	render_opps_a(t_Game *game, t_Opps *ops, int ox, int oy)
{
	t_nk	nk;
	t_nk	nk2;

	nk.i = ox;
	nk.j = oy;
	nk2.i = ops->x;
	nk2.j = ops->y;
	bis(game->d.mlx, game->d.mlx_win, game->t->til, nk);
	bis(game->d.mlx, game->d.mlx_win, game->t->o_a, nk2);
}

void	render_opps_s(t_Game *game, t_Opps *ops, int ox, int oy)
{
	t_nk	nk;
	t_nk	nk2;

	nk.i = ox;
	nk.j = oy;
	nk2.i = ops->x;
	nk2.j = ops->y;
	bis(game->d.mlx, game->d.mlx_win, game->t->til, nk);
	bis(game->d.mlx, game->d.mlx_win, game->t->o_s, nk2);
}

void	render_opps_d(t_Game *game, t_Opps *ops, int ox, int oy)
{
	t_nk	nk;
	t_nk	nk2;

	nk.i = ox;
	nk.j = oy;
	nk2.i = ops->x;
	nk2.j = ops->y;
	if (game->map[nk.i][nk.j] == '0')
		bis(game->d.mlx, game->d.mlx_win, game->t->til, nk);
	bis(game->d.mlx, game->d.mlx_win, game->t->o_d, nk2);
}
