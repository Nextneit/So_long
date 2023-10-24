/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:54:58 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/10/17 11:02:18 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_leaks(void)
{
	system("leaks -q a.out");
}

int	main()
{
	int		c;
	int		i;
	int		fd;
	int		l;
	char	*line;
	t_game	*game;

	atexit(ft_leaks);
	c = 0;
	l = 0;
	game->lines = l;
	fd = open("map.ber", 0);
	game = malloc(sizeof(t_game));
	line = get_next_line(fd);
	free(line);
	while (line != NULL)
	{
		game->lines++;
		line = get_next_line(fd);
		free(line);
	}
	close(fd);
	game->map = malloc(sizeof(char *) * l);
	i = 0;
	fd = open("map.ber", 0);
	while (i < game->lines)
	{
		line = get_next_line(fd);
		c = ft_strlen(line);
		if (line[c - 1] != '\n')
			c++;
		game->map[i] = malloc(sizeof(char) * c);
		ft_strlcpy(game->map[i], line, c);
		i++;
		free(line);
	}
	i = 0;
	while (i < l)
	{
		ft_printf("%s\n", game->map[i]);
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game);
	close(fd);
/*	mlx_t *mlx = mlx_init(500, 500, "SO LONG", 1);
	mlx_texture_t *t2 =  mlx_load_png("/Users/ncruz-ga/Desktop/so_long/images/floor.png");
	mlx_image_t *img2 = mlx_texture_to_image(mlx, t2);
	mlx_image_to_window(mlx, img2, 100, 100);

	mlx_texture_t *t3 =  mlx_load_png("/Users/ncruz-ga/Desktop/so_long/images/cofre_cerrado.png");
	mlx_image_t *img3 = mlx_texture_to_image(mlx, t3);
	mlx_image_to_window(mlx, img3, 100, 100);
	
	mlx_texture_t *t1 =  mlx_load_png("/Users/ncruz-ga/Desktop/so_long/images/cofre_abierto.png");
	mlx_image_t *img1 = mlx_texture_to_image(mlx, t1);
	mlx_image_to_window(mlx, img1, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);*/
}
