/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminerva <dminerva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:51:39 by dminerva          #+#    #+#             */
/*   Updated: 2021/05/18 02:16:23 by dminerva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int	ft_linelen(char *str, int i)
{
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str, int *i)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
		num = num * 10 + (str[(*i)++] - 48);
	return (num * sign);
}

void	map_check_suport(t_all *s, int *i, int *j)
{
	if (s->map.map[*i][*j + 1] == ' ' || \
		s->map.map[*i][*j - 1] == ' ' || \
		s->map.map[*i + 1][*j] == ' ' || \
		s->map.map[*i - 1][*j] == ' ' || \
		s->map.map[*i][*j + 1] == '\0')
	{
		printf("Error\nError map is not closed\n");
		exit(0);
	}
}

void	first_end(t_all *s, int *y, int i)
{
	while (s->map.map[*y][i] != '\0')
	{
		if (s->map.map[*y][i] == '0')
		{
			printf("Error\nError zamk_map6662\n");
			exit(0);
		}
		i++;
	}
	(*y)++;
}

void	map_check(t_all *s)
{
	int	i;
	int	j;

	i = 0;
	while (s->map.map[i])
	{
		j = 0;
		if (i == 0 || i == s->map.y -1)
			first_end(s, &i, 0);
		else if (i != s->map.y -1)
		{
			while (s->map.map[i][j])
			{
				if (s->map.map[i][j] == '0')
					map_check_suport(s, &i, &j);
				j++;
			}
			i++;
		}	
	}
}
