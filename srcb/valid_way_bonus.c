/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:33:29 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/11/02 10:53:32 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_way(t_game *game, t_point size, t_point current)
{
	if (current.x >= size.x || current.y >= size.y || current.x < 0
		|| current.y < 0 || game->map_copy[current.y][current.x] == '1'
		|| game->map_copy[current.y][current.x] == '*'
		|| game->map_copy[current.y][current.x] == 'M')
		return ;
	if (game->map_copy[current.y][current.x] == 'C')
		game->coin_copy++;
	if (game->map_copy[current.y][current.x] == 'E')
	{
		game->exit_copy++;
		game->local_exit.x = current.x;
		game->local_exit.y = current.y;
	}
	game->map_copy[current.y][current.x] = '*';
	valid_way(game, size, (t_point){current.x - 1, current.y});
	valid_way(game, size, (t_point){current.x + 1, current.y});
	valid_way(game, size, (t_point){current.x, current.y - 1});
	valid_way(game, size, (t_point){current.x, current.y + 1});
}
