/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:05:56 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/10/24 11:19:37 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define IMG_W 48
# define IMG_H 48
# define SIZE  48

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_game
{
	char			**map;
	char			**map_copy;
	t_point			local_exit;
	int				lines;
	int				columns;
	int				coin;
	int				coin_copy;
	int				player;
	t_point			p_position;
	int				exit;
	int				exit_copy;
	int				moves;
	mlx_t			*mlx;
	mlx_texture_t	*text_clo_chest;
	mlx_image_t		*img_clo_chest;
	mlx_texture_t	*text_op_chest;
	mlx_image_t		*img_op_chest;
	mlx_texture_t	*text_floor;
	mlx_image_t		*img_floor;
	mlx_texture_t	*text_wall;
	mlx_image_t		*img_wall;
	mlx_texture_t	*text_coin;
	mlx_image_t		*img_coin;
	mlx_texture_t	*text_p_up;
	mlx_image_t		*img_p_up;
	mlx_texture_t	*text_p_down;
	mlx_image_t		*img_p_down;
	mlx_texture_t	*text_p_right;
	mlx_image_t		*img_p_right;
	mlx_texture_t	*text_p_left;
	mlx_image_t		*img_p_left;
}					t_game;

int		read_map(t_game *game, char *map_name);
int		check_format(char *map_name);
int		check_map(t_game *game);
void	valid_way(t_game *game, t_point size, t_point current);
int		image_error(t_game *game);
void	clean_textures(t_game *game);
int		image_to_window(t_game *game);
void	resize_window(int width, int height, void *param);
void	free_all(t_game *game);
void	player_move(mlx_key_data_t keydata, void *param);
void	close_game(void *param);

#endif

//gcc -Wall -Wextra -Werror so_long.c check_map.c read_map.c player.c valid_way.c resize.c image.c libft/libft.a MLX42/libmlx42.a -Iinclude -lglfw -L"/Users/$USER/.brew/opt/glfw/lib/"