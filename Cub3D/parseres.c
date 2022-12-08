/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseres.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminerva <dminerva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:52:39 by dminerva          #+#    #+#             */
/*   Updated: 2021/05/18 00:52:41 by dminerva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int	get_res(char *str, t_all *s, int i)
{
	if (s->win.x != 0 || s->win.y != 0)
		s->err.err_res = -12;
	if (s->err.err_res == -12)
		return (ft_linelen(str, 0) + 2);
	res_chek(str, s);
	if (s->err.err_res < 0)
		return (ft_linelen(str, 0) + 2);
	s->win.x = ft_atoi(str, &i);
	s->win.y = ft_atoi(str, &i);
	if (str[i] != '\n')
		s->err.err_res = -13;
	res_err(s);
	s->err.err_line = 1;
	return (ft_linelen(str, 0) + 2);
}

void	res_err(t_all *s)
{
	if (s->win.x > s->mlx.screen_x || s->win.y > s->mlx.screen_y)
	{
		s->win.x = s->mlx.screen_x;
		s->win.y = s->mlx.screen_y;
	}
	if (s->win.x < 1 || s->win.y < 1)
	{
		s->win.x = DEFAULT_X;
		s->win.y = DEFAULT_Y;
		s->err.err_res = -10;
	}
}

int	ft_numcnt(char *str, t_all *s)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i] != '\n')
	{
		s->err.err_res = -11;
		return (i);
	}
	if (i > 4)
	{
		s->win.x = s->mlx.screen_x;
		s->win.y = s->mlx.screen_y;
	}
	return (i);
}

void	res_chek(char *str, t_all *s)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	i += ft_numcnt(&str[i], s);
	if (s->err.err_res == -11)
	{
		s->win.x = DEFAULT_X;
		s->win.y = DEFAULT_Y;
		return ;
	}
	while (str[i] == ' ')
		i++;
	i += ft_numcnt(&str[i], s);
	if (s->err.err_res == -11)
	{
		s->win.x = DEFAULT_X;
		s->win.y = DEFAULT_Y;
		return ;
	}
}
