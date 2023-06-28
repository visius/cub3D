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
	int sign;

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
void map_check_suport(t_all *s, int *i, int *j)
{
	if (s->map.map[*i][*j] == '0')
	{
		if (s->map.map[*i][*j + 1] == ' ' || \
			s->map.map[*i][*j - 1] == ' ' || \
			s->map.map[*i + 1][*j] == ' ' || \
			s->map.map[*i - 1][*j] == ' ' || \
			s->map.map[*i][*j + 1] == '\0')
		{
			printf("Error\nError zamk_mapˆˆˆ\n");
			exit(0);
		}
	}
}

void map_check(t_all *s)
{
	int i;
	int j;

	i = 0;
	while (i < s->map.y)
	{
		j = 0;
		while (s->map.map[i][j])
		{
			map_check_suport(s, &i, &j);
			j++;
		}
		i++;
	}
}

int		ft_mapcheck1(t_all *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < s->map.y)
	{
		j = 0;
		while (j < s->map.x)
		{
			if (s->map.map[i][j] != '1' && i == 0)
				return (-1);
			else if (s->map.map[i][j] != '1' && i == s->map.y - 1)
				return (-1);
			else if (s->map.map[i][j] != '1' && j == 0)
				return (-1);
			else if (s->map.map[i][j] != '1' && j == s->map.x - 1)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	if (!s1 || !s1)
		return (0);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	cub_exit(t_all *s)
{
	mlx_destroy_window(s->mlx.mlx, s->win.pwin);
	exit(0);
}

unsigned int	light(t_all *s, double light)
{
	int		r;
	int		g;
	int		b;
	double	lhypot;
	int		color;

	color = 0x00C0C0C0;
	lhypot = hypot(s->pos.x - s->hit.x, s->pos.y - s->hit.y);
	light = 1 - lhypot / light;
	r = (color / (256 * 256) % 256) * light;
	g = (color / 256 % 256) * light;
	b = (color % 256) * light;
	return (r * 256 * 256 + g * 256 +b);
}
