/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_func_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:50:25 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/26 15:22:39 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs_bonus/so_long_bonus.h"

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
	int	error;

	error = 0;
	error += valid_nbr_player(map);
	error += valid_nbr_exit(map);
	error += valid_nbr_collectibles(map);
	if (error > 0)
		return (1);
	return (0);
}
