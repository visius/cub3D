/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminerva <dminerva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:54:20 by dminerva          #+#    #+#             */
/*   Updated: 2021/05/18 00:54:22 by dminerva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int	file_check(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			j = ft_strcmp(&str[i], ".cub");
		if (j == 1)
			return (1);
		i++;
	}
	return (0);
}

void	cub_errors(t_all *s, char *str, int no)
{
	printf("%s - %d\n", str, no);
	s->err.is_error = -1;
}

void	print_error(t_all *s)
{
	if (s->err.save == -80)
		cub_errors(s, "File parametr error", s->err.save);
	if (s->err.err_line == 0)
		cub_errors(s, "Parametr error", s->err.err_line);
	if (s->err.err_tex < 0)
		cub_errors(s, "Texture error", s->err.err_tex);
	if (s->err.err_res != 0)
		cub_errors(s, "Resolution error", s->err.err_res);
	if (s->err.err_map != 0)
		cub_errors(s, "Map error", s->err.err_map);
	if (s->err.err_color != 0)
		cub_errors(s, "Color error", s->err.err_color);
	if (s->err.is_error == -1)
		exit(0);
}
