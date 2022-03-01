/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <crondeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:01:54 by crondeau          #+#    #+#             */
/*   Updated: 2022/03/01 15:30:44 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h> 
# include "get_next_line.h"

# define TILE_SIZE 64
# define GREEN "\033[38;5;22m"
# define RESET "\033[0m"

typedef struct s_spritz
{
	int		width;
	int		height;
	void	*img;
}	t_spritz;

typedef	struct s_image
{
	t_spritz	buisson;
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
	int		moove;
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
	t_image		texture;
	t_map		map;
	t_player	player;
}	t_data;


/////////////////////////PARSING//////////////////////////

int		map_ber(char *argv); // ok
int		directory_check(char *argv); // ok
int		check_char(char *line); // ok
int		count_line_col(t_map *map, char *argv); // ok
int		fill_map(t_data *data, char *path); // ok

////////////////////////////UTILS_LIBFT/////////////////////////

void	*ft_memset(void *string, int c, size_t n); // ok
void	ft_bzero (void *pointer, size_t count); // ok
void	*ft_calloc(size_t count, size_t size); // ok
int		ft_strlen(char *str); // ok
void	ft_putnbr(int n);

////////////////////////////ERRORS/////////////////////////

int		ft_check_error(int argc, char **argv, t_data *data); //2
int		error_code(t_data *data, int code); // ok

//////////////////////CHECK ERRORS////////////////////// OK

void	position_letters(t_data *data, int i); // ok
int		check_args(t_data *data); // ok
int		check_letters(t_data *data); // ok
int		check_wall(char *str); // ok
int		check_walls_around(t_data *data); // ok

//////////////////////FREE///////////////////////

void	ft_free(void *tofree); // ok
int		ft_free_dchar(char **str); // ok
void	destroy_mlx_imgs(t_data *data); // OK
void	destroy_mlx_imgs2(t_data *data);
void	endgame(t_data *data); // ok


////////////////////RENDER//////////////////////////

void	render_wall(t_data *data, int i, int j); // ok
void	parsing_display(t_data *data, int i, int j); // ok
void	print_moves(t_data *data); // ok
int		count_collectible(t_data data); // ok
void	display_map(t_data data); // ok


///////////////////DISPLAY////////////////

void	ultimate_image_init(t_data *data); // ok
void	ultimate_image_init2(t_data *data);
void    image_init(t_data *data, char *path, t_spritz *text); // ok

///////////move player////////////////

void	move_up(t_data *data); // ok
void	move_down(t_data *data); // ok
void	move_left(t_data *data); // ok
void	move_right(t_data *data); // ok
int		is_exit_opened(t_data *data); // ok


////////////////EVENTS/////////////////////////

void	move_player(t_data *data, char keypress); // ok
int		key_hook(int keycode, t_data *data); // ok
int		handle_exit_button(t_data *data); // ok

int		check_image_init(t_data *data); // ok



#endif