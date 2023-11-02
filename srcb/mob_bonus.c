/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:44:03 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/11/02 11:58:22 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_img2(t_game *game)
{
	game->text_mob = mlx_load_png("./images/slow_drake");
	game->text_mob2 = mlx_load_png("./images/slow_drake2");
	game->img_mob = mlx_texture_to_image(game->mlx, game->text_mob);
	game->img_mob2 = mlx_texture_image(game->mlx, game->text_mob2);
}

void	counter(t_game *game)
{
	char	*counter;

	counter = ft_itoa(game->moves);
	mlx_image_to_window(game->mlx, game->img_wall, 0, 0);
	mlx_put_string(game->mlx, counter, 5, 5);
	free(counter);
}

void	mob_sprite(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'M')
			{
				mlx_image_to_window(game->mlx, game->img_floor, j * SIZE,
					i * SIZE);
				mlx_image_to_window(game->mlx, game->img_mob, j * SIZE,
					i * SIZE);
			}
			j++;
		}
		i++;
	}
	game->m_moves = 1;
}

void	mob_sprite_2(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'M')
			{
				mlx_image_to_window(game->mlx, game->img_floor, j * SIZE,
					i * SIZE);
				mlx_image_to_window(game->mlx, game->img_mob2, j * SIZE,
					i * SIZE);
			}
			j++;
		}
		i++;
	}
	game->m_moves = 0;
}
