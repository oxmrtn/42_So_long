/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:20:51 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/26 16:07:05 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs_bonus/so_long_bonus.h"

t_Player	*create_player(int x, int y)
{
	t_Player	*player;

	player = malloc(sizeof(t_Player));
	if (!player)
		return (NULL);
	player->x = x;
	player->y = y;
	player->w = 0;
	player->lvl = 0;
	return (player);
}

t_Food	*create_food(int x, int y)
{
	t_Food	*food;

	food = malloc(sizeof(t_Food));
	if (!food)
		return (NULL);
	food->eaten = 0;
	food->x = x;
	food->y = y;
	return (food);
}

t_Exit	*create_exit(int x, int y)
{
	t_Exit	*exit;

	exit = malloc(sizeof(t_Exit));
	if (!exit)
		return (NULL);
	exit->is_open = 0;
	exit->x = x;
	exit->y = y;
	return (exit);
}

t_Opps	*create_opps(int x, int y)
{
	t_Opps	*opps;

	opps = malloc(sizeof(t_Opps));
	if (!opps)
		return (NULL);
	opps->x = x;
	opps->y = y;
	return (opps);
}

t_Game	*create_game(int fd)
{
	t_Game	*game;
	int		cpt_food;
	int		cpt_opps;

	cpt_opps = 0;
	cpt_food = 0;
	game = malloc(sizeof(t_Game));
	if (!game)
		return (NULL);
	ft_parser(fd, &(game->map));
	close(fd);
	game->opps_list = NULL;
	if (!game->map || valid_map_requirement(game->map))
	{
		if (game->map)
			free_map(game->map);
		else
			ft_putstr_fd("Error\nInvalid Map", 2);
		free(game);
		exit(0);
	}
	if (create_map(game, &cpt_food, &cpt_opps) || cpt_food == 0)
		return (need_space(cpt_food, game), NULL);
	return (add_food(cpt_food, game), add_opps(cpt_opps, game), game);
}
