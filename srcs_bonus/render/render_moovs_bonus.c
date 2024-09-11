/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_moovs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:21:03 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/03 16:18:14 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs_bonus/so_long_bonus.h"

void	render_moovs(t_Game *game)
{
	char	*result;

	result = ft_itoa(game->moov);
	if (!result)
		return ;
	mlx_put_image_to_window(game->d.mlx, game->d.mlx_win, game->t->tl_c, 0, 0);
	mlx_string_put(game->d.mlx, game->d.mlx_win, 20, 20, 0, result);
	free(result);
}
