/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:02:05 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/10/24 11:36:44 by ncruz-ga         ###   ########.fr       */
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
	ft_printf("Numero de movimientos: %d", game->moves);
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
	ft_printf("Numero de movimientos: %d\n", game->moves);
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
	ft_printf("Numero de movimientos: %d\n", game->moves);
}

static void	keypress(t_game *game, int x, int y, void *img)
{
	if (game->map[y][x] == 'C')
		move_player_c(game, x, y, img);
	else if (game->map[y][x] == 'E' && game->coin == game->coin_copy)
		close_game(game);
	else if (game->map[y][x] == 'E')
		move_player_e(game, x, y, img);
	else if (game->map[y][x] != '1')
		move_player_0(game, x, y, img);
}

void	player_move(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_game(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		keypress(game, game->p_position.x - 1, game->p_position.y,
			game->img_p_left);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		keypress(game, game->p_position.x, game->p_position.y + 1,
			game->img_p_down);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		keypress(game, game->p_position.x + 1, game->p_position.y,
			game->img_p_right);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		keypress(game, game->p_position.x, game->p_position.y - 1,
			game->img_p_up);
}
