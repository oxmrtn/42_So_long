/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrullar <mtrullar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:42:05 by mtrullar          #+#    #+#             */
/*   Updated: 2024/07/26 16:06:01 by mtrullar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/incs/ft_printf.h"
# include "../mlx/mlx.h"
# include <time.h>

typedef struct t_Player
{
	int		x;
	int		y;
	int		w;
	int		lvl;
}				t_Player;

typedef struct t_Exit
{
	int		x;
	int		y;
	int		is_open;
}				t_Exit;

typedef struct t_Food
{
	int		x;
	int		y;
	int		eaten;
}				t_Food;

typedef struct t_Opps
{
	int	x;
	int	y;
}				t_Opps;
typedef struct t_Texture
{
	void	*bl_c;
	void	*br_c;
	void	*tl_c;
	void	*tr_c;
	void	*w_u;
	void	*w_b;
	void	*w_r;
	void	*w_l;
	void	*wal;
	void	*o_e;
	void	*c_e;
	void	*o_w;
	void	*o_a;
	void	*o_s;
	void	*o_d;
	void	*p_1w;
	void	*p_1a;
	void	*p_1s;
	void	*p_1d;
	void	*p_2w;
	void	*p_2a;
	void	*p_2s;
	void	*p_2d;
	void	*p_3w;
	void	*p_3a;
	void	*p_3s;
	void	*p_3d;
	void	*til;
	void	*col;
	int		w;
	int		h;
}				t_Texture;

typedef struct t_Windows
{
	int	h;
	int	w;
}				t_Windows;

typedef struct t_Mlx_data
{
	void		*mlx;
	void		*mlx_win;
	t_Windows	win;
}				t_Mlx_data;

typedef struct t_Game
{
	char		**map;
	t_Player	*player;
	t_Exit		*exit;
	t_Food		**food_list;
	t_Opps		**opps_list;
	t_Mlx_data	d;
	t_Texture	*t;
	int			moov;
}				t_Game;

typedef struct t_nk
{
	int	i;
	int	j;
}				t_nk;

t_Game		*create_game(int fd);
t_Game		*init_struct(int fd);

t_Exit		*create_exit(int x, int y);

t_Food		*create_food(int x, int y);

t_Player	*create_player(int x, int y);

t_Opps		*create_opps(int x, int y);

int			nbr_collectible(t_Game *game);
int			nbr_opps(t_Game *game);
int			is_playable(t_Game *game);
int			ft_check_map(t_Game *game);
int			is_exit_reachable(int x, int y, char **map);
int			valid_map_requirement(char **map);
int			verif_ext(char *str);
int			create_map(t_Game *game, int *cpt_food, int *cpt_opps);
int			ft_random(int min, int max);
int			ops_movements_w(t_Game *game, t_Opps *ops);
int			ops_movements_a(t_Game *game, t_Opps *ops);
int			ops_movements_s(t_Game *game, t_Opps *ops);
int			ops_movements_d(t_Game *game, t_Opps *ops);
int			opps_turn(t_Game *game);

void		need_space(int cpt, t_Game *game);
void		free_game(t_Game *game);
void		free_game_pre(t_Game *game);
void		free_game_2(t_Game *game);
void		free_struct_tab(t_Game *game);
void		is_door_open(t_Game *game);
void		ft_move_d(t_Game *game);
void		ft_move_w(t_Game *game);
void		ft_move_s(t_Game *game);
void		ft_move_a(t_Game *game);
void		init_texture(t_Game *game);
void		render_map(t_Game *game);
void		render_moovs(t_Game *game);
void		clear_image(t_Game *game);
void		eat_collectible(int x, int y, t_Game *game);
void		render_player_w(t_Game *game, int px, int py);
void		render_player_a(t_Game *game, int px, int py);
void		render_player_s(t_Game *game, int px, int py);
void		render_player_d(t_Game *game, int px, int py);
void		render_opps_w(t_Game *game, t_Opps *ops, int ox, int oy);
void		render_opps_a(t_Game *game, t_Opps *ops, int ox, int oy);
void		render_opps_s(t_Game *game, t_Opps *ops, int ox, int oy);
void		render_opps_d(t_Game *game, t_Opps *ops, int ox, int oy);
void		add_food(int cpt_food, t_Game *game);
void		add_opps(int cpt_opps, t_Game *game);
void		is_collectible_reachable(int x, int y, char **map, int *cpt);
void		ft_parser(int fd, char ***map);
void		free_map(char **map);
void		ft_print_map(char **map);

#endif