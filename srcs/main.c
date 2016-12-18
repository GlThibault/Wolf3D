/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:50:28 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/18 16:40:11 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_close(void)
{
	exit(1);
	return (0);
}

int		key_hook(int keycode, t_wolf3d *t)
{
	if (keycode == 53)
		exit(1);
	t->delete1 = 1;
	return (0);
}

void	mlx_win_init(t_wolf3d *t)
{
	char	*title;

	t->posX = 22;
	t->posX = 12;
	t->dirX = -1;
	t->dirY = 0;
	t->planeX = 0;
	t->planeY = 0.66;
	title = ft_strjoin("Wolf3d : ", t->map_name);
	t->mlx = mlx_init();
	t->win = mlx_new_window(t->mlx, winX, winY, title);
	t->img = mlx_new_image(t->mlx, winX, winY);
	t->img_ptr = mlx_get_data_addr(t->img, &t->bpp, &t->sl, &t->endian);
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
	mlx_key_hook(t->win, key_hook, t);
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	mlx_string_put(t->mlx, t->win, 10, 10, 0xFFFFFF, "Wolf3d");
	mlx_loop(t->mlx);
}
