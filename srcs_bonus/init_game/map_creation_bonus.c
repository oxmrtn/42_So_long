/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:26:51 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/26 13:35:39 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs_bonus/so_long_bonus.h"

int	create_map(t_Game *game, int *cpt_food, int *cpt_opps)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[++i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->player = create_player(i, j);
			else if (game->map[i][j] == 'E')
				game->exit = create_exit(i, j);
			else if (game->map[i][j] == 'C')
				*cpt_food += 1;
			else if (game->map[i][j] == 'O')
				*cpt_opps += 1;
			else if (!ft_strchr("PECO10", game->map[i][j]))
				return (1);
			j++;
		}
	}
	return (0);
}

int	calc_h(t_Game *game)
{
	int	i;

	i = 0;
	if (!game->map)
		return (0);
	while (game->map[i])
		i++;
	return (64 * i);
}

int	calc_w(t_Game *game)
{
	int	i;

	i = 0;
	i = (int)ft_strlen(game->map[0]);
	return (i * 64);
}

t_Game	*init_struct(int fd)
{
	t_Game	*game;

	srand(time(NULL));
	game = create_game(fd);
	close(fd);
	if (!game)
	{
		ft_putstr_fd("Error\nMap creation has failed", 2);
		exit (0);
	}
	game->d.mlx = NULL;
	game->d.mlx_win = NULL;
	if (ft_check_map(game))
		free_game(game);
	game->d.win.w = calc_w(game);
	game->d.win.h = calc_h(game);
	if (game->d.win.h > 1080 || game->d.win.w > 1920)
	{
		ft_putstr_fd("Error\nMap bigger than screen", 2);
		free_game(game);
	}
	game->moov = 0;
	return (game);
}
