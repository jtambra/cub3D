/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <jtambra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 21:17:50 by jtambra           #+#    #+#             */
/*   Updated: 2021/05/10 19:04:46 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

# define ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_Q 12
# define KEY_E 14
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# define MOVE_SPEED 0.06
# define ROTATION 0.06

typedef struct s_screen
{
	unsigned char	beatmap_file[54];
}					t_screen;

typedef struct s_key
{
	char			w;
	char			s;
	char			a;
	char			d;
	char			q;
	char			e;
}					t_keys;

typedef struct s_sprites
{
	int		*sprite_order;
	double	*sprite_dist;
	double	sprite_x;
	double	sprite_y;
	double	inv;
	double	transform_x;
	double	transform_y;
	int		screen_x;
	int		sprite_h;
	int		sprite_w;
	int 	draw_start_x;
	int 	draw_end_x;
	int		draw_start_y;
	int		draw_end_y;
	int		stripe;
	int		tex_coor_x;
	int		tex_coor_y;
	int		d;
}					t_sprites;

typedef struct s_raycast
{
	size_t			w;
	size_t			h;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	double			old_dir_x;
	double			old_plane_x;
	int				step_x;
	int				step_y;
	int				wall_flag;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				color;
}					t_raycast;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_data;

typedef struct s_textures
{
	t_data			*main;
	t_data			north;
	t_data			south;
	t_data			east;
	t_data			west;
	t_data			sprite;
}					t_textures;

typedef struct s_draw
{
	double			wall_coor;
	int				texture_coor_x;
	int				texture_coor_y;
	double			increment;
	double			texture_pos;
	int				y;
	uint32_t		color;
}					t_draw;

typedef struct s_position
{
	double			x;
	double			y;
}					t_position;

typedef struct s_parse
{
	size_t			res[2];
	char			*texture_arr[5];
	long long int	color_arr[2];
	int				flags[8];
	char			**map;
	size_t			map_rows;
	char			view;
	int				sprites;
	t_position		player;
	t_position		*sprite_arr;
}					t_parse;

typedef struct s_config
{
	void			*mlx;
	void			*mlx_win;
	t_raycast		raycast;
	t_data			data;
	t_parse			parse;
	t_keys			keys;
	t_draw			draw;
	t_textures		textures;
	t_screen		screen;
	t_sprites		sprites;
}					t_config;

void		ft_init_config(t_config *config);
void		open_window(t_config *config);
void		make_screenshot(t_config *config);
void		ft_open_file(const char *file, t_config *config);
int			ft_check_config(int *array_flags);
void		ft_parse_line(char *line, t_parse *parse);
void		ft_parse_resolution(char *line, t_parse *parse, int counter);
void		ft_parse_texture(char *line, t_parse *parse, int counter);
void		ft_parse_color(char *line, t_parse *parse, int counter);
int			ft_str_isdigit(char *str);
void		ft_parse_map(char *line, t_parse *parse);
int			ft_arrlen(char **arr);
void		ft_free_strs(char **strs);
void		ft_free_all(char *line, t_parse *parse);
void		ft_check_map(char *line, t_parse *parse);
void		ft_parse_position(t_parse *parse);
void		ft_check_config_map(t_parse *parse);
void		free_param(char *line, t_parse *parse, char *str, char *error);
void		free_params(char *line, t_parse *parse, char **strs, char *error);
void		free_param(char *line, t_parse *parse, char *str, char *error);
void		calculations(t_config *config, int x);
void		calc_start_draw(t_config *config);
void		init_images(t_config *config);
void		calc_texture(t_config *config, int x);
void		draw_textures(t_config *config, int x);
void		draw_sprites(double *z_buffer, t_config *config);
t_position	*malloc_sp(t_config *config, int *order, double *dist, int amount);
void		drawing(t_config *config, t_sprites *sprites, double *z_buffer);
void		calc_sprite_params(t_config *config, t_sprites *sprites, int i);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			move_forward_backward(t_config *config);
int			move_left_right(t_config *config);
void		turn_left_right(t_config *config);
void		render(t_config *config);
void		set_direction(t_config *config);
void		put_param(t_config *config);
void		player_move(t_config *config);
int			pressed_key(int keycode, t_config *config);
int			unpressed_key(int keycode, t_config *config);
void		get_sprite(t_config *config);
void		get_east(t_config *config);
void		get_west(t_config *config);
void		get_south(t_config *config);
void		get_north(t_config *config);
void		ft_exit_cub(char *line);
int			raycasting(t_config *config);
int			ft_strcmp(char *s, char *d);

#endif
