/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <pcarmeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:17:24 by cliza             #+#    #+#             */
/*   Updated: 2022/01/26 21:24:22 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <fcntl.h>
# include <string.h>
# include "../libft/libft.h"
# include "../minilibx_opengl/mlx.h"

# define HEIGHT 1080
# define WIDTH 1920
# define TEX 512
# define MS 0.1
# define RS 0.07

typedef struct s_params
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			floor[3];
	int			ceiling[3];
	char		player_sym;
	char		**map;
	int			player_x;
	int			player_y;
	int			width;
	int			height;
}	t_params;

typedef struct s_mini_map
{
	int		mini_x;
	int		mini_y;
	double	x;
	double	y;
	double	stepx;
	double	stepy;
}				t_mini_map;

typedef struct s_door
{
	int				type;
	int				drawstart;
	int				drawend;
	double			step;
	int				texy;
	int				texx;
	double			texpos;
	struct s_door	*next;
}			t_door;

typedef struct s_ray
{
	int		check;
	int		hit;
	int		side;
	double	step;
	int		texy;
	int		texx;
	int		mapy;
	int		mapx;
	int		stepy;
	int		stepx;
	double	texpos;
	int		drawend;
	double	camerax;
	double	raydiry;
	double	raydirx;
	double	sidedistx;
	double	sidedisty;
	int		drawstart;
	double	deltadisty;
	double	deltadistx;
	int		lineheight;
	double	perpwalldist;
}			t_ray;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_texture
{
	int			x;
	int			y;
	int			size_line;
	int			endian;
	int			bpp;
	void		*img;
	char		*addr;
}				t_texture;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	e;
	int	esc;
	int	left;
	int	right;
}				t_keys;

typedef struct s_cube
{
	void		*mlx;
	void		*win;
	t_keys		*key;
	t_img		*img;
	t_texture	*tex;
	t_ray		*ray;
	t_door		*doors;
	int			floor[3];
	int			ceiling[3];
	int			width;
	int			height;
	char		**map;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		map_scale;
}				t_cube;

void		move(t_cube *cube);
void		move_right(t_cube *cube);
void		move_left(t_cube *cube);
void		move_backward(t_cube *cube);
void		move_forward(t_cube *cube);
void		rot_right(t_cube *cube);
void		rot_left(t_cube *cube);

int			get_color(t_texture *tex, int x, int y);
void		apply_pixel(t_img *img, int x, int y, int color);
int			rgb_channel(t_texture *tex, int x, int y, int i);
int			get_color_img(t_img *tex, int x, int y);
int			rgb_channel_img(t_img *tex, int x, int y, int i);

void		check_cubemap(t_mini_map map, t_cube *cube);
void		draw_mini_map(t_cube *cube);
void		dda(t_cube *cube, t_ray *ray);
void		step_and_side(t_cube *cube, t_ray *ray);

void		rot_mouse(t_cube *cube);
void		draw_walls(t_cube *cube);
void		draw_terra_sky(t_cube *cube);
void		texturing(t_cube *cube, t_ray *ray, int x);
void		tex_pos_init(t_cube *cube, t_ray *ray);

t_door		*new_door(t_cube *cube, t_ray *ray, int type);
void		add_door_front(t_door **doors, t_door *new_door);
void		draw_doors(t_cube *cube, t_door *doors, int x);
void		free_doors(t_door **doors);
int			key_release(int key, t_cube *cube);
int			key_press(int key, t_cube *cube);

int			can_move(t_cube *cube, int x, int y);
int			closer(void);
void		use(t_cube *cube);
void		blue_portal(t_cube *cube);
void		orange_portal(t_cube *cube);
void		init_cube(t_cube *cube, t_params *params);
void		ray_step(t_ray *ray);

void		init_ray(t_cube *cube, t_ray *ray, int x);
void		init_plane(t_cube *cube, t_params *params);
void		init_texture(t_cube *cube, t_texture *tex, char *path);
void		init_dir(t_cube *cube, t_params *params);
void		shifting_colors(t_cube *cube, t_params *params);
void		init_cube(t_cube *cube, t_params *params);
void		init_cube2(t_cube *cube, t_params *params);

int			ft_error(char *str);
int			player_pos_check(char **map, t_params *params);
void		check(char **map_arr, t_params *params, int x, int y);
void		walls_checking(char **map_arr, t_params *params);
void		check_texture(char **params_line, char **params_name);
int			check_colors(char **params_line, int *params_values);
int			params_dealing(char *line, t_params *params, int *num);
int			record_map(int num, int empty_line, char *line, char **map);
char		*map_reading(int fd, t_params *params, char **map);
void		init_params(t_params *params);
int			define_map_size(char *line, t_params *params);
t_params	*parser(char **argv);
int			arr_len(char **array2);
void		arr_free(char **array2);
char		**arr_create(t_params *params);
void		map_filing(char *map, char **map_arr, int w, int h);
int			is_digitstr(char *str);
int			file_checking(char *file_name);

#endif