/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_tab_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:06:21 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/03 16:16:43 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs_bonus/so_long_bonus.h"

void	add_food(int cpt_food, t_Game *game)
{
	int			i;
	int			j;
	int			cpt;

	cpt = 0;
	i = 0;
	j = 0;
	game->food_list = malloc(sizeof(t_Food) * (cpt_food + 1));
	if (!game->food_list)
		return ;
	while (game->map[i] && cpt < cpt_food)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
			{
				game->food_list[cpt] = create_food(i, j);
				cpt++;
			}
			j++;
		}
		i++;
	}
	game->food_list[cpt] = NULL;
}

void	add_opps(int cpt_opps, t_Game *game)
{
	int			i;
	int			j;
	int			cpt;

	cpt = 0;
	i = 0;
	j = 0;
	if (cpt_opps == 0)
		return ;
	game->opps_list = malloc(sizeof(t_Food) * (cpt_opps + 1));
	if (!game->opps_list)
		return ;
	while (game->map[i] && cpt < cpt_opps)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'O')
				game->opps_list[cpt++] = create_opps(i, j);
			j++;
		}
		i++;
	}
	game->opps_list[cpt] = NULL;
}

int	nbr_collectible(t_Game *game)
{
	int	i;

	i = 0;
	if (!game->food_list)
		return (0);
	while (game->food_list[i])
	{
		i++;
	}
	return (i);
}

int	nbr_opps(t_Game *game)
{
	int	i;

	i = 0;
	if (!game->opps_list)
		return (0);
	while (game->opps_list[i])
	{
		i++;
	}
	return (i);
}

int	ft_random(int min, int max)
{
	return (rand() % (max - min +1));
}
