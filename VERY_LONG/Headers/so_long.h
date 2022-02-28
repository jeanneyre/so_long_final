#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h> 
# include <fcntl.h>
# include "get_next_line.h"
# include <X11/keysym.h>
# include <limits.h>

# define NOEVENTMASK 0L
# define DESTROYNOTIFY 17
# define TILE_SIZE 64
# define GREEN "\033[38;5;22m"
# define RESET "\033[0m"


enum s_key
{
	EK_ESC = 65307,
};

typedef struct s_spritz
{
	int		width;
	int		height;
	void	*img;
	int		bits_per_pixl;
	int		line_lenth;
	int		endian;
	char	*addr;
}	t_spritz;

typedef	struct s_image
{
	t_spritz	new_grass;
	t_spritz	exit;
	t_spritz	wall_down;
	t_spritz	wall_up;
	t_spritz	wall_left;
	t_spritz	wall_right;
	t_spritz	augustin;
	t_spritz	teddy_bear;
	t_spritz	corner_d_l;
	t_spritz	corner_d_r;
	t_spritz	corner_u_l;
	t_spritz	corner_u_r;
}	t_image;

typedef struct s_player
{
	int		p_x; 
	int		p_y;
	int		player;
	int		collected;
}	t_player;

typedef	struct s_map
{
	int		x;
	int		y;
	int		collectible;
	char	**map;
	int		exit;			//verif lors du parsing
}	t_map;

typedef struct	s_data 
{
	void		*win;
	void		*mlx;
	void		*image;
	int			collectible;
	int			win_width;
	int			win_height;
	t_image		texture;
	t_map		map;
	t_player	player;
	t_spritz	screen;
}	t_data;


/////////////////////////PARSING//////////////////////////

int		map_ber(char *argv);
int		directory_check(char *argv);
int		check_wall(char *str);
int		check_walls_around(t_data *data);
int		check_char(char *line);
void	ft_free(void *tofree);
int		count_line_col(t_map *map, char *argv);
int		ft_free_dchar(char **str);
int		fill_map(t_data *data, char *path);

////////////////////////////UTILS/////////////////////////

void	*ft_memset(void *string, int c, size_t n);
void	ft_bzero (void *pointer, size_t count);
void	*ft_calloc(size_t count, size_t size);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		count_unit(int n);
char	*ft_itoa(int n);
int		ft_strlen(char *str);

////////////////////////////MAP/////////////////////////

int		check_args(t_data *data);
void	position_letters(t_data *data, int i);
int		check_letters(t_data *data);
int		check_char(char *line);
void	display_map(t_data data);


/////////////////////////EVENT////////////////////////////

int		key_hook(int keycode, t_data *sl);
void	move_player(t_data *data, char keypress);

///////////////////////INIT///////////////////////////////
void	init_all(t_data *data);

///////////////////////PUT TO SCREEN//////////////////////
void	start_putting_img(t_data *data);


// Fais par R44_BOOT
int	error_code(t_data *data, int code);

void	endgame(t_data *data);




//NEW WITH CRIS

int	fill_map(t_data *data, char *path);
int	check_all_errors(t_data *data, char *str);
int	directory_check(char *argv);
void	ft_free(void *tofree);

//NEW WITH ROMAIN

//size_t	int_len(int i);
//size_t	len(char *str);
//size_t	strdog(char *ret, char *add);
//char	*ultimate_strcat(t_data *data, char *path, int index);
void	screen_init(t_data *data);
void	ultimate_image_init(t_data *data);
void    image_init(t_data *data, char *path, t_spritz *text); 
//static unsigned int	get_px_xy(t_spritz *img, int x, int y);
//static void	set_px_xy(t_spritz *img, int x, int y, int color);
//void	fill_image(t_spritz *screen, t_spritz *img, int x, int y);
//void	reverse_fill_image(t_spritz *screen, t_spritz *img, int x, int y);

////////////////NEW/////////////////////////

int		handle_exit_button(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		is_exit_opened(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	move_player(t_data *data, char keypress);
void	render_wall(t_data *data, int i, int j);
void	parsing_display(t_data *data, int i, int j);
void	print_moves(t_data *data);


#endif