#include "so_long.h"

void init_game(t_game *game, char *file_path)
{
    initi_map(game, file_path);
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, game->width * 24, game->height * 24, "so_long");
    game->count = 0;
    init_img(game);
    render_map(game);
    mlx_hook(game->win, 2, 1L << 0, keyboard, game);
    mlx_hook(game->win, 17, 1L << 17, exit_game, game);
    mlx_loop(game->mlx);
}

void initi_map(t_game *game, char *file_path)
{
    
    ft_map_height(game, file_path);
    ft_read_map(game, file_path);
    if (!ft_map_wall(game) || !ft_map_width(game) || !validate_player_count(game) || validate_map_elements(game)) 
    {
        printf("Mapa inválido\n");
        free_map(game->map);
        exit (1);
    }
    game->map_cpy = copy_map(game->map, game->height);
    if (!game->map_cpy)
    {
        printf("Erro ao copiar o mapa\n");
        free_map(game->map);
        exit (1);
    }
    flood_fill(game, game->player_x, game->player_y);
    if (ft_validate_map_flood_fill(game))
    {
        printf("Mapa inválido após flood fill\n");
        free_map(game->map);
        exit (1);
    }
    if (ft_validate_map_flood_fill(game))
    {
        printf("Mapa inválido após flood fill\n");
        free_map(game->map);
        exit (1);
    }
        free_map(game->map_cpy);
}


void init_img(t_game *game)
{
    game->wall_img = mlx_xpm_file_to_image(game->mlx, "/home/andre/42/so_long/textures/wall.xpm", &game->width, &game->height);
    game->floor_img = mlx_xpm_file_to_image(game->mlx, "/home/andre/42/so_long/textures/chao.xpm", &game->width, &game->height);
    game->player_img = mlx_xpm_file_to_image(game->mlx, "/home/andre/42/so_long/textures/player.xpm", &game->width, &game->height);
    game->exit_img = mlx_xpm_file_to_image(game->mlx, "/home/andre/42/so_long/textures/exit.xpm", &game->width, &game->height);
    game->collect_img = mlx_xpm_file_to_image(game->mlx, "/home/andre/42/so_long/textures/Item.xpm", &game->width, &game->height);
}
void render_map(t_game *game)
{
	int x, y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				put_image(game, game->wall_img, x, y);
			else if (game->map[y][x] == '0')
				put_image(game, game->floor_img, x, y);
			else if (game->map[y][x] == 'C')
				put_image(game, game->collect_img, x, y);
			else if (game->map[y][x] == 'P')
				put_image(game, game->player_img, x, y);
			else if (game->map[y][x] == 'E')
				put_image(game, game->exit_img, x, y);
			x++;
		}
		y++;
	}
	
}
void put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 24, y * 24);
}
