/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:51:03 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/20 21:23:20 by tglandai         ###   ########.fr       */
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

# define winX 1024
# define winY 768
# define USAGE "usage: wolf3d \"map\"\n"

typedef struct	s_wolf3d
{
	int			**map;
	int			nb_lines;
	int			lenline;
	int			bpp;
	int			endian;
	int			sl;
	char		*map_name;
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	double		x_pos;
	double		y_pos;
	double		x_dir;
	double		y_dir;
	double		x_plane;
	double		y_plane;
	double		time;
	double		oldTime;
	double		x_cam;
	double		x_rayPos;
	double		y_rayPos;
	double		x_rayDir;
	double		y_rayDir;
	int			x_map;
	int			y_map;
	double		x_sideDist;
	double		y_sideDist;
	double		x_deltaDist;
	double		y_deltaDist;
	double		wallDist;
	int			x_step;
	int			y_step;
	int			hit;
	int			side;
	int			lineHeight;
	int			start;
	int			end;
	double		x_oldDir;
	double		x_oldPlane;
	double		ms;
	double		rs;
}				t_wolf3d;

void			draw_line(int x, t_wolf3d *t, int clor);
void			put_pxl_to_img(t_wolf3d *t, int x, int y, int color);
int				key_hook(int keycode, t_wolf3d *t);
int				key_hook2(int keycode, t_wolf3d *t);
int				ft_close(void);
void			mlx_win_init(t_wolf3d *t);
void			wolf3d_init(t_wolf3d *t);
int				parser(t_wolf3d *t, char **av);
int				parser2(t_wolf3d *t, char **av);
void			ray_casting(t_wolf3d *t);
void			ray_casting_init(t_wolf3d *t, int x);
void			dda(t_wolf3d *t);
void			dda_init(t_wolf3d *t);
#endif
