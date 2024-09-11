/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:32:07 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/25 18:07:18 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	free_map(char **map)
{
	size_t	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

void	free_game(t_Game *game)
{
	int	i;

	i = 0;
	if (game->player)
		free(game->player);
	if (game->exit)
		free(game->exit);
	if (game->food_list && game->food_list[i])
	{
		while (game->food_list[i])
			free(game->food_list[i++]);
		free(game->food_list);
	}
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
	if (game->food_list && game->food_list[i])
	{
		while (game->food_list[i])
			free(game->food_list[i++]);
		free(game->food_list);
	}
	if (game->map)
		free_map(game->map);
	if (game->t)
		clear_image(game);
	if (game->d.mlx)
	{
		mlx_destroy_display(game->d.mlx);
		free(game->d.mlx);
	}
	free(game);
	exit (0);
}
