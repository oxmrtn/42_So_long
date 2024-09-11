/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:15:02 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/03 16:57:06 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static void	bis(void *mlx, void *win, void *img, t_nk nk)
{
	mlx_put_image_to_window(mlx, win, img, nk.j * 64, nk.i * 64);
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
			if (game->map[nk.i][nk.j] == '1')
				bis(game->d.mlx, game->d.mlx_win, game->t->wal, nk);
			else
				bis(game->d.mlx, game->d.mlx_win, game->t->gro, nk);
			if (game->map[nk.i][nk.j] == 'P')
				bis(game->d.mlx, game->d.mlx_win, game->t->pla, nk);
			if (game->map[nk.i][nk.j] == 'C')
				bis(game->d.mlx, game->d.mlx_win, game->t->col, nk);
			if (game->map[nk.i][nk.j] == 'E' && game->exit->is_open)
				bis(game->d.mlx, game->d.mlx_win, game->t->o_d, nk);
			else if (game->map[nk.i][nk.j] == 'E' && !game->exit->is_open)
				bis(game->d.mlx, game->d.mlx_win, game->t->c_d, nk);
			nk.j++;
		}
		nk.i++;
	}
}
