/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_playable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:52:26 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/26 16:10:26 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

char	**ft_map_copy(char **map)
{
	char	**result;
	int		i;

	i = 0;
	while (map[i])
		i++;
	result = malloc(sizeof(char *) * (i + 1));
	if (!result)
		return (NULL);
	i = 0;
	if (!result)
		return (NULL);
	while (map[i])
	{	
		result[i] = ft_strdup(map[i]);
		i++;
	}
	result[i] = NULL;
	return (result);
}

int	is_playable(t_Game *game)
{
	char	**mapcopy;
	int		error;
	int		col_c;

	error = 0;
	col_c = 0;
	mapcopy = ft_map_copy(game->map);
	if (!is_exit_reachable(game->player->x, game->player->y, mapcopy))
	{
		error = 1;
		ft_putstr_fd("Error\nThe exit is not reachable", 2);
	}
	free_map(mapcopy);
	mapcopy = ft_map_copy(game->map);
	is_collectible_reachable(game->player->x, game->player->y, mapcopy, &col_c);
	free_map(mapcopy);
	if (col_c != nbr_collectible(game))
	{
		error = 1;
		ft_putstr_fd("Error\nOne of the collectible is not reachable", 2);
	}
	return (error);
}
