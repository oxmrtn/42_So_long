/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_status_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:36:54 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/26 13:03:41 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs_bonus/so_long_bonus.h"

static void	*bis(void *ptr, char *p, int *w, int *h)
{
	return (mlx_xpm_file_to_image(ptr, p, w, h));
}

static void	init_texture_2(t_Game *game)
{
	int	h;
	int	w;

	h = 64;
	w = 64;
	game->t->p_1w = bis(game->d.mlx, "./text/p1_w.xpm", &w, &h);
	game->t->p_1a = bis(game->d.mlx, "./text/p1_a.xpm", &w, &h);
	game->t->p_1s = bis(game->d.mlx, "./text/p1_s.xpm", &w, &h);
	game->t->p_1d = bis(game->d.mlx, "./text/p1_d.xpm", &w, &h);
	game->t->p_2w = bis(game->d.mlx, "./text/p2_w.xpm", &w, &h);
	game->t->p_2a = bis(game->d.mlx, "./text/p2_q.xpm", &w, &h);
	game->t->p_2s = bis(game->d.mlx, "./text/p2_s.xpm", &w, &h);
	game->t->p_2d = bis(game->d.mlx, "./text/p2_d.xpm", &w, &h);
	game->t->p_3w = bis(game->d.mlx, "./text/p3_w.xpm", &w, &h);
	game->t->p_3a = bis(game->d.mlx, "./text/p3_a.xpm", &w, &h);
	game->t->p_3s = bis(game->d.mlx, "./text/p3_s.xpm", &w, &h);
	game->t->p_3d = bis(game->d.mlx, "./text/p3_d.xpm", &w, &h);
	game->t->til = bis(game->d.mlx, "./text/tiles.xpm", &w, &h);
	game->t->col = bis(game->d.mlx, "./text/coll.xpm", &w, &h);
	game->t->o_a = bis(game->d.mlx, "./text/o_a.xpm", &w, &h);
	game->t->o_s = bis(game->d.mlx, "./text/o_s.xpm", &w, &h);
	game->t->o_d = bis(game->d.mlx, "./text/ox_d.xpm", &w, &h);
}

void	init_texture(t_Game *game)
{
	int	h;
	int	w;

	h = 64;
	w = 64;
	game->t = malloc(sizeof(t_Texture));
	if (!game->t)
		free_game(game);
	game->t->w = 64;
	game->t->h = 64;
	game->t->bl_c = bis(game->d.mlx, "./text/bl_corner.xpm", &w, &h);
	game->t->br_c = bis(game->d.mlx, "./text/br_corner.xpm", &w, &h);
	game->t->tl_c = bis(game->d.mlx, "./text/tl_corner.xpm", &w, &h);
	game->t->tr_c = bis(game->d.mlx, "./text/tr_corner.xpm", &w, &h);
	game->t->w_u = bis(game->d.mlx, "./text/wall_up.xpm", &w, &h);
	game->t->w_b = bis(game->d.mlx, "./text/wall_down.xpm", &w, &h);
	game->t->w_r = bis(game->d.mlx, "./text/wall_right.xpm", &w, &h);
	game->t->w_l = bis(game->d.mlx, "./text/wall_left.xpm", &w, &h);
	game->t->wal = bis(game->d.mlx, "./text/wall.xpm", &w, &h);
	game->t->o_e = bis(game->d.mlx, "./text/d_o.xpm", &w, &h);
	game->t->c_e = bis(game->d.mlx, "./text/d_c.xpm", &w, &h);
	game->t->o_w = bis(game->d.mlx, "./text/o_w.xpm", &w, &h);
	init_texture_2(game);
}

void	clear_image_2(t_Game *game)
{
	mlx_destroy_image(game->d.mlx, game->t->p_2w);
	mlx_destroy_image(game->d.mlx, game->t->p_2a);
	mlx_destroy_image(game->d.mlx, game->t->p_2s);
	mlx_destroy_image(game->d.mlx, game->t->p_2d);
	mlx_destroy_image(game->d.mlx, game->t->p_3w);
	mlx_destroy_image(game->d.mlx, game->t->p_3a);
	mlx_destroy_image(game->d.mlx, game->t->p_3s);
	mlx_destroy_image(game->d.mlx, game->t->p_3d);
	mlx_destroy_image(game->d.mlx, game->t->col);
	mlx_destroy_image(game->d.mlx, game->t->til);
}

void	clear_image(t_Game *game)
{
	mlx_destroy_image(game->d.mlx, game->t->bl_c);
	mlx_destroy_image(game->d.mlx, game->t->br_c);
	mlx_destroy_image(game->d.mlx, game->t->tl_c);
	mlx_destroy_image(game->d.mlx, game->t->tr_c);
	mlx_destroy_image(game->d.mlx, game->t->w_u);
	mlx_destroy_image(game->d.mlx, game->t->w_b);
	mlx_destroy_image(game->d.mlx, game->t->w_r);
	mlx_destroy_image(game->d.mlx, game->t->w_l);
	mlx_destroy_image(game->d.mlx, game->t->wal);
	mlx_destroy_image(game->d.mlx, game->t->o_e);
	mlx_destroy_image(game->d.mlx, game->t->c_e);
	mlx_destroy_image(game->d.mlx, game->t->o_w);
	mlx_destroy_image(game->d.mlx, game->t->o_a);
	mlx_destroy_image(game->d.mlx, game->t->o_s);
	mlx_destroy_image(game->d.mlx, game->t->o_d);
	mlx_destroy_image(game->d.mlx, game->t->p_1w);
	mlx_destroy_image(game->d.mlx, game->t->p_1a);
	mlx_destroy_image(game->d.mlx, game->t->p_1s);
	mlx_destroy_image(game->d.mlx, game->t->p_1d);
	clear_image_2(game);
}
