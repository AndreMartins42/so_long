/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:50:06 by anmendes          #+#    #+#             */
/*   Updated: 2025/04/05 16:24:50 by anmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_game 
{   
	char	**map;
	char	**map_cpy;
	int		width;
	int		height;
	int		p;
	int		c;
	int		e;
	int		player_x;
	int		player_y;
	void	*mlx;
	void	*win;
	int		count;
	void	*player_img;
	void	*exit_img;
	void	*collect_img;
	void	*floor_img;  
	void	*wall_img;
}   t_game;

char    *get_next_line(int fd);
char    *read_file(int fd, char *cache);
char    *ft_line(char *buffer);
char    *ft_next(char *buffer);
int     ft_strlcpy(char *dst, char *src, int size);
char    *ft_strdup(char *s);
char    *ft_strjoin(char *s1, char *s2);//JANELA
char    *ft_strchr(char *s, int c);
int     ft_strlen(char *str);
void	initi_map(t_game *game, char *file_path);
int		ft_read_map(t_game *game, char *file_path);
void	ft_map_height(t_game *game, char *file_path);
int		ft_map_wall(t_game *game);
int		ft_map_width(t_game *game);
void	free_map(char **map);
void	clear_get_next_line_buffer(char **buffer);
int		validate_player_count(t_game	*game);
int		ft_validate_char(char c);
int		validate_map_elements(t_game *game);
char	**copy_map(char **map, int height);
void	flood_fill(t_game *game, int x, int y);
int		ft_validate_map_flood_fill(t_game *game);
void	initi_win(t_game *game);
int		close_window(t_game *game);
void	destroy_window_and_mlx(t_game *game);
int		keyboard(int keysym, t_game *game);
void	cleanup(t_game *game);
int		exit_game(t_game *game);
void	init_img(t_game *game);
void	put_image(t_game *game, void *img, int x, int y);
void	init_game(t_game *game, char *file_path);
void	render_map(t_game *game);
void	move_player(t_game *game, int x, int y);
int		ber_check(char *argv);
#endif
