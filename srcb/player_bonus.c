/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:02:05 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/11/02 12:07:49 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player_e(t_game *game, int x, int y, void *img)
{
	mlx_image_to_window(game->mlx, game->img_floor, game->p_position.x * SIZE,
		game->p_position.y * SIZE);
	game->p_position.x = x;
	game->p_position.y = y;
	mlx_image_to_window(game->mlx, game->img_clo_chest,
		game->p_position.x * SIZE, game->p_position.y * SIZE);
	mlx_image_to_window(game->mlx, img, game->p_position.x * SIZE,
		game->p_position.y * SIZE);
	game->moves++;
}

static void	move_player_0(t_game *game, int x, int y, void *img)
{
	mlx_image_to_window(game->mlx, game->img_floor, game->p_position.x * SIZE,
		game->p_position.y * SIZE);
	if (game->map[game->p_position.y][game->p_position.x] == 'E')
		mlx_image_to_window(game->mlx, game->img_clo_chest,
			game->p_position.x * SIZE, game->p_position.y * SIZE);
	game->p_position.x = x;
	game->p_position.y = y;
	mlx_image_to_window(game->mlx, img, game->p_position.x * SIZE,
		game->p_position.y * SIZE);
	game->moves++;
}

static void	move_player_c(t_game *game, int x, int y, void *img)
{
	mlx_image_to_window(game->mlx, game->img_floor, game->p_position.x * SIZE,
		game->p_position.y * SIZE);
	if (game->map[game->p_position.y][game->p_position.x] == 'E')
		mlx_image_to_window(game->mlx, game->img_clo_chest,
			game->p_position.x * SIZE, game->p_position.y * SIZE);
	game->p_position.x = x;
	game->p_position.y = y;
	game->map[game->p_position.y][game->p_position.x] = '0';
	mlx_image_to_window(game->mlx, game->img_floor, game->p_position.x * SIZE,
		game->p_position.y * SIZE);
	mlx_image_to_window(game->mlx, img, game->p_position.x * SIZE,
		game->p_position.y * SIZE);
	game->coin++;
	game->moves++;
	if (game->coin == game->coin_copy)
		mlx_image_to_window(game->mlx, game->img_op_chest,
			game->local_exit.x * SIZE, game->local_exit.y * SIZE);
}

static void	keypress(t_game *game, int x, int y, void *img)
{
	if (game->map[y][x] == 'C')
	{
		move_player_c(game, x, y, img);
		counter(game);
	}
	if (game->map[y][x] == 'E' && game->coin == game->coin_copy)
		close_game(game);
	else if (game->map[y][x] == 'E')
	{
		move_player_e(game, x, y, img);
		counter(game);
	}
	else if (game->map[y][x] != '1')
	{
		move_player_0(game, x, y, img);
		counter(game);
	}
}

void	player_move(mlx_key_data_t data, void *param)
{
	t_game	*game;

	game = param;
	if (data.key == MLX_KEY_A || data.key == MLX_KEY_S || data.key == MLX_KEY_D
		|| data.key == MLX_KEY_W && data.action == MLX_PRESS)
	{
		if (game->m_moves == 0)
			mob_sprite(game);
		else
			mob_sprite_2(game);
	}
	if (data.key == MLX_KEY_ESCAPE && data.action == MLX_PRESS)
		close_game(game);
	if (data.key == MLX_KEY_A && data.action == MLX_PRESS)
		keypress(game, game->p_position.x - 1, game->p_position.y,
			game->img_p_left);
	if (data.key == MLX_KEY_S && data.action == MLX_PRESS)
		keypress(game, game->p_position.x, game->p_position.y + 1,
			game->img_p_down);
	if (data.key == MLX_KEY_D && data.action == MLX_PRESS)
		keypress(game, game->p_position.x + 1, game->p_position.y,
			game->img_p_right);
	if (data.key == MLX_KEY_W && data.action == MLX_PRESS)
		keypress(game, game->p_position.x, game->p_position.y - 1,
			game->img_p_up);
}
