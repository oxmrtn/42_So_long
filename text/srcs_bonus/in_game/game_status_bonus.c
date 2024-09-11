/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_status_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:41:30 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/03 15:55:52 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs_bonus/so_long_bonus.h"

void	is_door_open(t_Game *game)
{
	int	count_eaten;
	int	i;

	if (!game->food_list)
		return ;
	i = 0;
	count_eaten = 0;
	while (game->food_list[i])
	{
		if (game->food_list[i]->eaten)
			count_eaten++;
		i++;
	}
	if (count_eaten == i)
		game->exit->is_open = 1;
}

void	eat_collectible(int x, int y, t_Game *game)
{
	int	i;

	i = 0;
	while (game->food_list[i])
	{
		if (game->food_list[i]->x == x && game->food_list[i]->y == y)
		{
			game->food_list[i]->eaten = 1;
			is_door_open(game);
			game->player->lvl++;
		}
		i++;
	}
}
