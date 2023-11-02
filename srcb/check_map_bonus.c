/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:50:37 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/10/24 11:35:28 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_format(char *map_name)
{
	int	i;

	i = 0;
	i = ft_strlen(map_name);
	if ((map_name[i - 1] == 'r' && map_name[i - 2] == 'e')
		&& (map_name[i - 3] == 'b' && map_name[i - 4] == '.'))
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

static int	check_wall(t_game *game)
{
	int	i;
	int	k;

	i = 0;
	k = game->lines - 1;
	while (game->map[0][i] != '\0')
	{
		if (game->map[0][i] != '1')
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (game->map[k][i] != '\0')
	{
		if (game->map[k][i] != '1')
			return (EXIT_FAILURE);
		i++;
	}
	i--;
	while (k-- > 0)
	{
		if (game->map[k][0] != '1' || game->map[k][i] != '1')
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_map_2(t_game *game)
{
	int	i;
	int	k;

	i = 0;
	k = game->lines;
	while (--k >= 0)
	{
		while (game->map[k][i] != '\0')
		{
			if (game->map[k][i] != '1' && game->map[k][i] != '0'
				&& game->map[k][i] != 'C' && game->map[k][i] != 'P'
					&& game->map[k][i] != 'E')
				return (EXIT_FAILURE);
			i++;
		}
		i = 0;
	}
	return (EXIT_SUCCESS);
}

static int	count_objects(t_game *game)
{
	int	i;
	int	k;

	k = game->lines;
	while (--k > 0)
	{
		i = -1;
		while (game->map[k][++i] != '\0')
		{
			if (game->map[k][i] == 'C')
				game->coin++;
			else if (game->map[k][i] == 'P')
			{
				game->player++;
				game->p_position.x = i;
				game->p_position.y = k;
			}
			else if (game->map[k][i] == 'E')
				game->exit++;
		}
	}
	if (game->coin == 0 || game->player != 1 || game->exit != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_map(t_game *game)
{
	int	i;
	int	k;

	i = 0;
	k = game->lines;
	i = ft_strlen(game->map[0]);
	while (--k >= 0)
		if (i != ft_strlen(game->map[k]))
			return (ft_printf("Error: Mapa no rectangular\n"), EXIT_FAILURE);
	if (count_objects(game) == 1)
		return (ft_printf("Error: Numero de elementos erroneo\n"), EXIT_FAILURE);
	if (check_map_2(game) == 1)
		return (ft_printf("Error: Elemento erroneo\n"), EXIT_FAILURE);
	if (check_wall(game) == 1)
		return (ft_printf("Error: Mapa no rodeado de muros\n"), EXIT_FAILURE);
	valid_way(game, (t_point){game->columns, game->lines}, game->p_position);
	if (game->coin != game->coin_copy || game->exit != game->exit_copy)
		return (ft_printf("Error: Camino no valido\n"), EXIT_FAILURE);
	game->coin = 0;
	return (EXIT_SUCCESS);
}
