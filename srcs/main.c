/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:50:28 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/31 14:05:21 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_textures(t_wolf3d *t)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	t->tex[0].img = mlx_xpm_file_to_image(t->mlx, "textures/wood.xpm", &a, &b);
	t->tex[0].data = mlx_get_data_addr(t->tex[0].img, &t->tex[0].bpp,
			&t->tex[0].sizeline, &t->tex[0].endian);
	t->tex[1].img = mlx_xpm_file_to_image(t->mlx, "textures/stone.xpm", &a, &b);
	t->tex[1].data = mlx_get_data_addr(t->tex[1].img, &t->tex[1].bpp,
			&t->tex[1].sizeline, &t->tex[1].endian);
	t->tex[2].img = mlx_xpm_file_to_image(t->mlx, "textures/mossy.xpm", &a, &b);
	t->tex[2].data = mlx_get_data_addr(t->tex[2].img, &t->tex[2].bpp,
			&t->tex[2].sizeline, &t->tex[2].endian);
	t->tex[3].img = mlx_xpm_file_to_image(t->mlx,
			"textures/redbrick.xpm", &a, &b);
	t->tex[3].data = mlx_get_data_addr(t->tex[3].img, &t->tex[3].bpp,
			&t->tex[3].sizeline, &t->tex[3].endian);
	t->tex[4].img = mlx_xpm_file_to_image(t->mlx, "textures/wood.xpm", &a, &b);
	t->tex[4].data = mlx_get_data_addr(t->tex[4].img, &t->tex[4].bpp,
			&t->tex[4].sizeline, &t->tex[4].endian);
}

int		ft_close(void)
{
	exit(1);
	return (0);
}

void	mlx_win_init(t_wolf3d *t)
{
	char	*title;

	title = ft_strjoin("Wolf3d : ", t->map_name);
	t->mlx = mlx_init();
	t->win = mlx_new_window(t->mlx, WINX, WINY, title);
	ft_strdel(&title);
}

void	wolf3d_init(t_wolf3d *t)
{
	t->x_pos = 3;
	t->y_pos = 3;
	t->x_dir = -1;
	t->y_dir = 0;
	t->x_plane = 0;
	t->y_plane = 0.66;
	t->ms = 0.05;
	t->rs = 0.05;
	t->move_up = 0;
	t->move_down = 0;
	t->move_left = 0;
	t->move_right = 0;
	t->x_text = 0;
	t->y_text = 0;
	load_textures(t);
}

int		main(int ac, char **av)
{
	t_wolf3d *t;

	if (ac != 2)
	{
		ft_putstr(USAGE);
		return (0);
	}
	if (!(t = (t_wolf3d *)malloc(sizeof(t_wolf3d))))
		return (0);
	if (!(parser(t, av)))
		return (0);
	mlx_win_init(t);
	mlx_hook(t->win, 17, 0L, ft_close, t);
	mlx_hook(t->win, 2, (1L << 0), key_press, t);
	mlx_hook(t->win, 3, (1L << 1), key_release, t);
	t->help = 1;
	wolf3d_init(t);
	ray_casting(t);
	mlx_loop_hook(t->mlx, move, t);
	mlx_loop(t->mlx);
}
