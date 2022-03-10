/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <crondeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:01:54 by crondeau          #+#    #+#             */
/*   Updated: 2022/03/02 09:56:34 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h> 
# include "get_next_line.h"

# define TILE_SIZE 64
# define YELLOW "\033[38;5;220m"
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


/////////////////////////PARSING///////////////////////////

int		map_ber(char *argv); 
int		directory_check(char *argv); 
int		check_char(char *line); 
int		count_line_col(t_map *map, char *argv); 
int		fill_map(t_data *data, char *path); 

///////////////////////UTILS_LIBFT/////////////////////////

void	*ft_memset(void *string, int c, size_t n); 
void	ft_bzero (void *pointer, size_t count); 
void	*ft_calloc(size_t count, size_t size); 
int		ft_strlen(char *str); 
void	ft_putnbr(int n);

/////////////////////////ERRORS///////////////////////////

int		ft_check_error(int argc, char **argv, t_data *data); 
int		error_code(t_data *data, int code); 

//////////////////////CHECK ERRORS////////////////////////

void	position_letters(t_data *data, int i); 
int		check_args(t_data *data); 
int		check_letters(t_data *data); 
int		check_wall(char *str); 
int		check_walls_around(t_data *data); 

//////////////////////////FREE/////////////////////////////

void	ft_free(void *tofree); 
int		ft_free_dchar(char **str); 
void	destroy_mlx_imgs(t_data *data); 
void	destroy_mlx_imgs2(t_data *data);
void	endgame(t_data *data); 


//////////////////////////RENDER//////////////////////////

void	render_wall(t_data *data, int i, int j); 
void	parsing_display(t_data *data, int i, int j); 
void	print_moves(t_data *data); 
int		count_collectible(t_data data); 
void	display_map(t_data data); 


///////////////////////////DISPLAY////////////////////////

void	ultimate_image_init(t_data *data); 
void	ultimate_image_init2(t_data *data);
void    image_init(t_data *data, char *path, t_spritz *text); 

///////////////////////MOVE PLAYER////////////////////////

void	move_up(t_data *data); 
void	move_down(t_data *data); 
void	move_left(t_data *data); 
void	move_right(t_data *data); 
int		is_exit_opened(t_data *data); 


/////////////////////////EVENTS////////////////////////////

void	move_player(t_data *data, char keypress); 
int		key_hook(int keycode, t_data *data); 
int		handle_exit_button(t_data *data); 

int		check_image_init(t_data *data); 



#endif