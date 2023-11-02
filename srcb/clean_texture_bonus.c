/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_texture_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:34:59 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/10/30 11:36:39 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	clean_textures(t_game *game)
{
	mlx_delete_texture(game->text_clo_chest);
	mlx_delete_texture(game->text_op_chest);
	mlx_delete_texture(game->text_floor);
	mlx_delete_texture(game->text_coin);
	mlx_delete_texture(game->text_wall);
	mlx_delete_texture(game->text_p_down);
	mlx_delete_texture(game->text_p_left);
	mlx_delete_texture(game->text_p_right);
	mlx_delete_texture(game->text_p_up);
	mlx_delete_texture(game->text_mob);
	mlx_delete_texxture(game->text_mob2);
}
