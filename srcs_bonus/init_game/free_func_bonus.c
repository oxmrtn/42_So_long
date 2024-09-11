/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:32:07 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/26 16:14:37 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs_bonus/so_long_bonus.h"

void	free_map(char **map)
{
	size_t	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_game_pre(t_Game *game)
{
	int	i;

	i = 0;
	if (game->map)
		free_map(game->map);
	free(game);
	exit (0);
}

void	free_game(t_Game *game)
{
	int	i;

	i = 0;
	if (game->player)
		free(game->player);
	if (game->exit)
		free(game->exit);
	free_struct_tab(game);
	if (game->map)
		free_map(game->map);
	free(game);
	exit (0);
}

void	free_game_2(t_Game *game)
{
	int	i;

	i = 0;
	if (game->player)
		free(game->player);
	if (game->exit)
		free(game->exit);
	free_struct_tab(game);
	if (game->map)
		free_map(game->map);
	if (game->t)
		clear_image(game);
	free(game->t);
	if (game->d.mlx)
	{
		mlx_destroy_display(game->d.mlx);
		free(game->d.mlx);
	}
	free(game);
	exit (0);
}

void	free_struct_tab(t_Game *game)
{
	int	i;

	i = 0;
	if (game->opps_list)
	{
		while (game->opps_list[i])
			free(game->opps_list[i++]);
		free(game->opps_list);
	}
	i = 0;
	if (game->food_list)
	{
		while (game->food_list[i])
			free(game->food_list[i++]);
		free(game->food_list);
	}
}
