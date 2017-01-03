/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:35:38 by tglandai          #+#    #+#             */
/*   Updated: 2017/01/03 12:54:59 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_map(char *buff, t_wolf3d *t)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	t->lenline = ft_linelen(buff);
	t->nb_lines = ft_countlines(buff);
	while (buff[i] && buff[i] != '\0')
	{
		if ((buff[i] < 48 || buff[i] > 57) && buff[i] != ' ' && buff[i] != '\n')
			return (0);
		len++;
		if (buff[i] == '\n')
		{
			if (len - 1 != t->lenline)
				return (0);
			len = 0;
		}
		i++;
	}
	return (1);
}

int		parser2(t_wolf3d *t, char **av)
{
	int		i;
	int		j;
	int		k;
	int		fd;
	char	*str;

	i = 0;
	fd = open(av[1], O_RDONLY);
	while (ft_get_next_line(fd, &str) > 0)
	{
		j = -1;
		k = 0;
		if (!(t->map[i] = (int *)malloc(sizeof(int) * t->lenline)))
			return (0);
		while (++j < t->lenline)
		{
			if (str[k] == ' ')
				k++;
			t->map[i][j] = ft_atoi(&str[k]);
			k++;
		}
		i++;
		free(str);
	}
	return (1);
}

int		check_side(t_wolf3d *t)
{
	int		i;

	i = 0;
	while (i < t->lenline)
	{
		if (t->map[0][i] == 0)
			return (0);
		if (t->map[t->nb_lines - 1][i] == 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < t->nb_lines)
	{
		if (t->map[i][0] == 0)
			return (0);
		if (t->map[i][t->lenline - 1] == 0)
			return (0);
		i++;
	}
	if (t->map[3][3] != 0)
		return (0);
	return (1);
}

int		parser(t_wolf3d *t, char **av)
{
	int		fd;
	char	*buff;
	int		i;

	i = 0;
	buff = ft_strnew(65536);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || (read(fd, buff, 65536)) < 1)
	{
		ft_putstr("wolf3d: ");
		ft_putstr(av[1]);
		ft_putstr(": No such file\n");
		return (0);
	}
	if (!(check_map(buff, t)))
	{
		ft_putstr("Map error\n");
		return (0);
	}
	while (buff[i] != '\0' && buff[i] != '\n')
	{
		if (buff[i] == ' ')
			t->lenline--;
		i++;
	}
	ft_strdel(&buff);
	t->map_name = av[1];
	close(fd);
	if (!(t->map = (int **)malloc(sizeof(int *) * t->nb_lines))
			|| !(parser2(t, av)))
		return (0);
	if (!check_side(t))
	{
		ft_putstr("Map error\n");
		return (0);
	}
	return (1);
}
