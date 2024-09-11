/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:17:08 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/26 12:58:51 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs_bonus/so_long_bonus.h"

int	close_win(t_Game *game)
{
	mlx_loop_end(game->d.mlx);
	return (0);
}

int	key_hook(int keycode, t_Game *game)
{
	int	end;

	end = 0;
	if (game->opps_list)
		end = opps_turn(game);
	if (end > 0)
		return (0);
	if (keycode == 65307)
		mlx_loop_end(game->d.mlx);
	else if (keycode == 119)
		ft_move_w(game);
	else if (keycode == 97)
		ft_move_a(game);
	else if (keycode == 115)
		ft_move_s(game);
	else if (keycode == 100)
		ft_move_d(game);
	return (0);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_Game		*g;

	g = NULL;
	if (argc != 2)
		return (ft_putstr_fd ("Error\nNo map specified", 2), 0);
	if (verif_ext(argv[1]))
		return (ft_putstr_fd("Error\nNot a .ber file", 2), 0);
	fd = open(argv[1], O_RDONLY);
	g = init_struct(fd);
	g->d.mlx = mlx_init();
	if (!g->d.mlx)
		free_game(g);
	g->d.mlx_win = mlx_new_window(g->d.mlx, g->d.win.w, g->d.win.h, "SO_LONG");
	init_texture(g);
	render_map(g);
	mlx_hook(g->d.mlx_win, 17, 0, close_win, g);
	mlx_key_hook(g->d.mlx_win, key_hook, g);
	mlx_loop(g->d.mlx);
	mlx_destroy_window(g->d.mlx, g->d.mlx_win);
	if (g->player->w == 1)
		ft_printf("YOU WIN\n");
	else
		ft_printf("YOU LOOSE\n");
	return (free_game_2(g), 1);
}
