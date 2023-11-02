/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:15:33 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/10/26 16:08:13 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	while (i <= game->lines)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	i = 0;
	while (i <= game->lines)
	{
		free(game->map_copy[i]);
		i++;
	}
	free(game->map_copy);
	free(game);
}

static int	allocate_map_2(char *line, t_game *game, int fd, char *map_name)
{
	int	i;

	i = -1;
	fd = open(map_name, 0);
	line = get_next_line(fd);
	while (++i < game->lines)
	{
		game->columns = ft_strlen(line);
		if (line[game->columns - 1] != '\n')
			game->columns++;
		game->map[i] = ft_calloc(game->columns, sizeof(char *));
		game->map_copy[i] = ft_calloc(game->columns, sizeof(char *));
		ft_strlcpy(game->map[i], line, game->columns);
		ft_strlcpy(game->map_copy[i], line, game->columns);
		free(line);
		line = get_next_line(fd);
	}
	game->columns--;
	game->map[i] = NULL;
	game->map_copy[i] = NULL;
	return (close(fd), free(line), EXIT_SUCCESS);
}

static int	allocate_map(char *line, t_game *game, int fd, char *map_name)
{
	fd = open(map_name, 0);
	line = get_next_line(fd);
	if (line == NULL)
		return (ft_printf("Error: Mapa vacio\n"), EXIT_FAILURE);
	while (line != NULL)
	{
		game->lines++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	game->map = ft_calloc(game->lines + 1, sizeof(char *));
	game->map_copy = ft_calloc(game->lines + 1, sizeof(char *));
	if (!game->map || !game->map_copy)
		return (free(line), EXIT_FAILURE);
	close(fd);
	if ((allocate_map_2(line, game, fd, map_name)) == 1)
		return (free(line), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	read_map(t_game *game, char *map_name)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(map_name, 0);
	if (fd < 0)
		return (ft_printf("Error: No se pudo abrir el mapa\n"), EXIT_FAILURE);
	if (allocate_map(line, game, fd, map_name) == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
