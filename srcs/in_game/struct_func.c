/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:50:25 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/26 15:21:18 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

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

int	valid_nbr_player(char **map)
{
	int	cpt_player;
	int	i;
	int	j;

	j = 0;
	i = 0;
	cpt_player = 0;
	if (!map)
	{
		ft_putstr_fd("Error\nParsing failed", 2);
		return (1);
	}
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			if (map[i][j++] == 'P')
				cpt_player++;
		i++;
	}
	if (cpt_player != 1)
		return (ft_putstr_fd("Error\nMore or less than 1 player", 2), 1);
	return (0);
}

int	valid_nbr_exit(char **map)
{
	int	cpt_sortie;
	int	i;
	int	j;

	j = 0;
	i = 0;
	cpt_sortie = 0;
	if (!map)
	{
		ft_putstr_fd("Error\nParsing failed", 2);
		return (1);
	}
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			if (map[i][j++] == 'E')
				cpt_sortie++;
		i++;
	}
	if (cpt_sortie != 1)
		return (ft_putstr_fd("Error\nThere is more or less than 1 exit", 2), 1);
	return (0);
}

int	valid_nbr_collectibles(char **map)
{
	int	cpt_collectibles;
	int	i;
	int	j;

	j = 0;
	i = 0;
	cpt_collectibles = 0;
	if (!map)
	{
		ft_putstr_fd("Error\nParsing failed", 2);
		return (1);
	}
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			if (map[i][j++] == 'E')
				cpt_collectibles++;
		i++;
	}
	if (cpt_collectibles < 1)
		return (1);
	return (0);
}

int	valid_map_requirement(char **map)
{
	if (valid_nbr_player(map))
		return (1);
	else if (valid_nbr_exit(map))
		return (1);
	else if (valid_nbr_collectibles(map))
		return (1);
	else
		return (0);
}
