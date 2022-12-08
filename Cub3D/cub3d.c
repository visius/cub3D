/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminerva <dminerva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:54:47 by dminerva          #+#    #+#             */
/*   Updated: 2021/05/18 22:48:43 by dminerva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int	draw(t_all *s)
{
	cub_input(s);
	fillcolor(s, 0, s->win.y / 2, s->tex.c);
	fillcolor(s, s->win.y / 2, s->win.y / 2, s->tex.f);
	cub_frame(s);
	fillcolor(s, 0, s->win.y / 10, 0x00000000);
	fillcolor(s, s->win.y - s->win.y / 10, s->win.y / 10, 0x00000000);
	if (s->err.save == 1)
		bmp_make(s);
	mlx_put_image_to_window(s->mlx.mlx, s->win.pwin, s->mlx.frame, 0, 0);
	mlx_string_put(s->mlx.mlx, s->win.pwin, 20, 20, 0x00FF9A00, "DAS_Game");
	mlx_do_sync(s->mlx.mlx);
	return (0);
}

void	cub(char **av)
{
	t_all		s;

	cub_init(&s);
	if (av[2] && ft_strcmp(av[2], "--save") == 1)
		s.err.save = 1;
	else if (av[2] && ft_strcmp(av[2], "--save") != 1)
		s.err.save = -80;
	s.mlx.mlx = mlx_init();
	mlx_get_screen_size(s.mlx.mlx, &s.mlx.screen_x, &s.mlx.screen_y);
	parsestart(&s, av[1]);
	print_error(&s);
	s.win.pwin = mlx_new_window(s.mlx.mlx, s.win.x, s.win.y, "SuperCub");
	s.mlx.frame = mlx_new_image(s.mlx.mlx, s.win.x, s.win.y);
	s.mlx.data = (int *)mlx_get_data_addr(s.mlx.frame, &s.mlx.bit, \
										&s.mlx.len, &s.mlx.end);
	s.hit.grad = (s.win.x * s.win.x) + (s.win.y * s.win.y);
	s.hit.grad = sqrt(s.hit.grad);
	mlx_loop_hook (s.mlx.mlx, draw, &s);
	mlx_hook(s.win.pwin, 2, 1, cub_key_press, &s);
	mlx_hook(s.win.pwin, 3, 1, cub_key_release, &s);
	mlx_hook(s.win.pwin, 17, 1, cub_exit, &s);
	mlx_loop(s.mlx.mlx);
}

int	main(int ac, char **av)
{
	int	j;

	j = file_check(av[1]);
	if (av[1] != NULL && ac >=2 && ac <= 3)
	{	
		if (j == 1)
			cub(av);
		else if (j == 0)
			printf("%s\n", "File format error");
	}	
	return (0);
}
