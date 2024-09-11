/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_ext_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:21:29 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/26 16:13:34 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs_bonus/so_long_bonus.h"

int	verif_ext(char *str)
{
	char	*ext;
	int		i;

	ext = ".ber";
	str++;
	while (*str != '.')
	{
		str++;
	}
	i = ft_strncmp(str, ext, 5);
	return (i);
}

void	need_space(int cpt, t_Game *game)
{
	if (cpt == 0)
	{
		ft_putstr_fd("Error\nThere is no collectibles", 2);
		if (game->player)
			free(game->player);
		if (game->exit)
			free(game->exit);
	}
	free_game_pre(game);
}
