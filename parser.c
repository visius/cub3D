#include"cub3d.h"

int	get_xpm(t_all *s, unsigned int **adr, void **ptr, char *str)
{
	int		fd;

	if ((fd = open(str, O_RDONLY)) < 0)
	{
		printf("%s - %s\n", str, "Texture error");
		exit(0);
		return (s->err.err_tex = -1);
	}
	close(fd);
	*ptr = mlx_xpm_file_to_image(s->mlx.mlx, str, &s->tex.xres, &s->tex.yres);
	*adr = (unsigned int *)mlx_get_data_addr(*ptr, &s->tex.bit, \
													&s->tex.len, &s->tex.end);
	s->err.err_tex = 1;
	printf("err = %d\n", s->err.err_tex);
	return (0);
}

int	gettexture(t_all *s, unsigned int **adr, void **ptr, char *str)
{
	int	fd;
	int	i;

	fd = 0;
	if (*ptr != NULL)
	{
		s->err.err_tex = -120;
		return (ft_linelen(str, 0) + 1);
	}
	i = ft_linelen(str, 0);
	str[i] = '\0';
	get_xpm(s, adr, ptr, str);
	str[i] = '\n';
	s->err.err_line = 1;
	return (i + 1);
}

int	getcolor(t_all *s, char *str, int *color)
{
	t_vector	col;

	col.a = -1;
	if (*color != -1)
	{
		s->err.err_color = -30;
		return (ft_linelen(str, 0) + 1);
	}
	parse_color(s, &col, str);
	*color = col.r * 256 * 256 + col.g * 256 + col.b;
	if (str[col.a] != '\n')
	{
		s->err.err_color = -62;
		while (str[col.a] != '\n')
			col.a++;
	}
	s->err.err_line = 1;
	return (col.a + 1);
}

void	parse_color(t_all *s, t_vector *col, char *str)
{
	while (str[++col->a] ==  ' ' || str[col->a] == '\n');
	col->r = ft_atoi(str, &col->a);
	comma(s, str, &col->a);
	col->g = ft_atoi(str, &col->a);
	comma(s, str, &col->a);
	col->b = ft_atoi(str, &col->a);
	if (col->r > 255 || col->g > 255 || col->b > 255)
		s->err.err_color = -60;
	else if (col->r < 0 || col->g < 0 || col->b < 0)
		s->err.err_color = -61;
}

void	comma(t_all *s, char *str, int *i)
{
	int	j;

	j = 0;
	while (str[++(*i)] == ' ' || str[*i] == ',')
		if (str[*i] == ',')
			j++;
	if (j > 1)
		s->err.err_color = -63;
}
