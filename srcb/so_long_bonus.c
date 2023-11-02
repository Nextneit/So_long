/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:38:49 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/10/30 10:40:57 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void ft_leaks(void)
{
	system("leaks -q so_long");
}*/

static void	initialize(t_game *game)
{
	game->map = NULL;
	game->map_copy = NULL;
	game->lines = 0;
	game->columns = 0;
	game->coin = 0;
	game->coin_copy = 0;
	game->player = 0;
	game->exit = 0;
	game->exit_copy = 0;
	game->moves = 0;
}

static int	init_image(t_game *game)
{
	game->text_clo_chest = mlx_load_png("./images/clo_chest.png");
	game->text_op_chest = mlx_load_png("./images/op_chest.png");
	game->text_floor = mlx_load_png("./images/floor.png");
	game->text_wall = mlx_load_png("./images/wall.png");
	game->text_coin = mlx_load_png("./images/coin.png");
	game->text_p_up = mlx_load_png("./images/ske_back.png");
	game->text_p_down = mlx_load_png("./images/ske_front.png");
	game->text_p_right = mlx_load_png("./images/ske_right.png");
	game->text_p_left = mlx_load_png("./images/ske_left.png");
	game->img_clo_chest = mlx_texture_to_image(game->mlx, game->text_clo_chest);
	game->img_op_chest = mlx_texture_to_image(game->mlx, game->text_op_chest);
	game->img_floor = mlx_texture_to_image(game->mlx, game->text_floor);
	game->img_wall = mlx_texture_to_image(game->mlx, game->text_wall);
	game->img_coin = mlx_texture_to_image(game->mlx, game->text_coin);
	game->img_p_up = mlx_texture_to_image(game->mlx, game->text_p_up);
	game->img_p_down = mlx_texture_to_image(game->mlx, game->text_p_down);
	game->img_p_right = mlx_texture_to_image(game->mlx, game->text_p_right);
	game->img_p_left = mlx_texture_to_image(game->mlx, game->text_p_left);
	init_img2(game);
	clean_textures(game);
	if (image_error(game) == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	close_game(void *param)
{
	t_game	*game;

	game = param;
	mlx_close_window(game->mlx);
}

int	aux_main(t_game *game)
{
	if (image_to_window(game) == 1)
		return (EXIT_FAILURE);
	mlx_key_hook(game->mlx, &player_move, game);
	mlx_close_hook(game->mlx, &close_game, game);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_printf("Error: No hay mapa\n"), EXIT_FAILURE);
	game = ft_calloc(1, sizeof(t_game));
	initialize(game);
	if ((check_format(argv[1])) == 1)
		return (ft_printf("Error: Formato de mapa incorrecto\n"), EXIT_FAILURE);
	if (read_map(game, argv[1]) == 1)
		return (free_all(game), EXIT_FAILURE);
	if ((check_map(game) == 1))
		return (free_all(game), EXIT_FAILURE);
	game->mlx = mlx_init(IMG_W * game->columns, IMG_H * game->lines,
			"SO_LONG", true);
	if (!game->mlx)
		return (free_all(game), EXIT_FAILURE);
	if (init_image(game) == 1)
		return (free_all(game), EXIT_FAILURE);
	if (aux_main(game) == 1)
		return (free_all(game), EXIT_FAILURE);
	mlx_resize_hook(game->mlx, &resize_window, NULL);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (free_all(game), EXIT_SUCCESS);
}
