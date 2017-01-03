/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:51:03 by tglandai          #+#    #+#             */
/*   Updated: 2017/01/03 11:52:33 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define WINX 1024
# define WINY 768
# define USAGE "usage: wolf3d \"map\"\n"

typedef struct	s_tex
{
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_tex;

typedef struct	s_wolf3d
{
	t_tex		tex[9];
	char		*map_name;
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			**map;
	int			nb_lines;
	int			lenline;
	int			bpp;
	int			endian;
	int			sl;
	int			x_map;
	int			y_map;
	int			x_step;
	int			y_step;
	int			hit;
	int			side;
	int			lineheight;
	int			start;
	int			end;
	int			color;
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
	int			help;
	int			x_text;
	int			y_text;
	int			id;
	int			texture;
	int			x_floortext;
	int			y_floortext;
	int			x;
	int			y;
	double		x_pos;
	double		y_pos;
	double		x_dir;
	double		y_dir;
	double		x_plane;
	double		y_plane;
	double		x_cam;
	double		x_raypos;
	double		y_raypos;
	double		x_raydir;
	double		y_raydir;
	double		x_sidedist;
	double		y_sidedist;
	double		x_deltadist;
	double		y_deltadist;
	double		walldist;
	double		x_olddir;
	double		x_oldplane;
	double		ms;
	double		rs;
	double		x_wall;
	double		x_floor;
	double		y_floor;
	double		x_curfloortext;
	double		y_curfloortext;
	double		curdist;
	double		weight;
}				t_wolf3d;

void			draw_sky(t_wolf3d *t);
void			draw_floor(t_wolf3d *t);
void			draw_wall(int x, int start, int end, t_wolf3d *t);
void			put_pxl_to_img(t_wolf3d *t, int x, int y, int color);

int				key_press2(int keycode, t_wolf3d *t);
int				key_press(int keycode, t_wolf3d *t);
int				key_release(int keycode, t_wolf3d *t);
void			move_side(t_wolf3d *t);
int				move(t_wolf3d *t);

void			help_text(t_wolf3d *t);

void			load_textures(t_wolf3d *t);
void			load_textures2(t_wolf3d *t, int a, int b);

int				ft_close(void);
void			mlx_win_init(t_wolf3d *t);
void			wolf3d_init(t_wolf3d *t);

int				check_map(char *buff, t_wolf3d *t);
int				parser(t_wolf3d *t, char **av);
int				parser2(t_wolf3d *t, char **av);

void			ray_casting(t_wolf3d *t);
void			ray_casting_init(t_wolf3d *t, int x);
void			floor_and_ceiling(t_wolf3d *t, int x);
void			dda(t_wolf3d *t);
void			dda_init(t_wolf3d *t);
#endif
