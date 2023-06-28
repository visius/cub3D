#ifndef CUB3D_H
# define CUB3D_H

#include "minilibx/mlx.h"
# include "cub_struct.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2
# define Q 12
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define SPACE 49
# define COMAND 259

# define DEFAULT_X 800
# define DEFAULT_Y 600

# define SPEED 30
# define TURN 0.04
# define TURN_INVERT 1
# define FOV 66


typedef struct		s_all
{
	t_win			win;
	t_tex			tex;
	t_map			map;
	t_mlx			mlx;
	t_dir			dir;
	t_ray			ray;
	t_move			move;
	t_pos			pos;
	t_err			err;
	t_hit			hit;
	t_spr			*spr;
	t_stk			*stk;
}					t_all;

//utils
int				ft_srtlen(char *str);
int				cub_strerror(int err);
int				ft_atoi(char *str, int *i);
int				ft_linelen(char *str, int i);
void			res_chek(char *str, t_all *s);
int				ft_strcmp(char *s1, char *s2);
int				ft_numcnt(char *str, t_all *s);

//parsing
void			cub_init(t_all *s);
void			parsestart(t_all *s, char *av);
int				dumpedfile(t_all *s, char *fname, int bufsize, char	**dumpf);
int				parse(char *str, t_all *s);
int				get_res(char *str, t_all *s, int i);
int				getcolor(t_all *s, char *str, int *color);
int				mapcnt(t_all *s, char *str, int i);
void			getmap(char *str, t_all *s);
char			*writeline(char *str, char *map, t_all *s, int y);
void			map_check(t_all *s);
void			map_check_suport(t_all *s, int *i, int *j);
void			map_aproov(t_all *s);
void			set_rotation(char c, t_all *s);
int				file_check(char *str);
void			res_err(t_all *s);
void			comma(t_all *s, char *str, int *i);
int				get_xpm(t_all *s, unsigned int **adr, void **ptr, char *file);
int				gettexture(t_all *s, unsigned int **adr, void **ptr, char *str);
void			parse_color(t_all *s, t_vector *col, char *str);

//input
int				cub_input(t_all *s);
void			cub_exit(t_all *s);
int				cub_mouse(t_all *s);
void			input_check(t_all *s);
int				cub_key_press(int keycode, t_all *s);
int				cub_key_release(int keycode, t_all *s);

//move
void			cub_strafe(double c, t_all *s);
void			cub_rotate(double c, t_all *s);
void			cub_moveforward(double c, t_all *s);

//cub
void			cub(char **av);
int				draw(t_all *s);
void			spawn_dir(t_all *s);
void			cub_hline (t_all *s);
unsigned int	light(t_all *s, double light);
unsigned int	get_pixel(t_all *s, double i);
void			draw_column(t_all *s, int size);
void			set_transform(char c, t_all *s, int x, int y);

//raycast
void			cub_ray(t_all *s);
void			ray_dir(t_all *s);
int				cub_frame(t_all *s);
void			ray_horizontal(t_all *s);
void			ray_verttical(t_all *s);

// sprite
void			cub_stock(t_all *s);
int				cub_slist(t_all *s);
int				spr_count(t_all *s);
void			cub_sprite(t_all *s);
void			cub_sorder(t_all *s);
void			cub_sdraw(t_all *s, int loc, double dist);
void			cub_slocate(t_all *s, double dirx, double diry, double dist);

void			fil_one(t_all *s);
void			fillcolor(t_all *s, int posy, int h, int c);

//bmp
void			bmp_make(t_all *s);
static void		bmp_header(t_all *s, int fd);
static void		dib_header(t_all *s, int fd);
void			bmp_write(t_all *s, int fd, int x, int y);

void			tex_init(t_all *s);
void			err_init(t_all *s);
void			base_init(t_all *s);

void			print_error(t_all *s);
void			cub_errors(t_all *s, char *str, int no);


//------------------temp-----------------//

void drawlinevert(t_all *s, int posx, int h, int c);

int				ft_mapcheck1(t_all *s);

int	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

#endif