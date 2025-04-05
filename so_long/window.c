#include "so_long.h"

int keyboard(int keysym, t_game *game)
{
    if (keysym == 65307)
    {
        exit_game(game);
        exit(0);
    }
    else if (keysym == 119)
       move_player(game, 0, -1);
    else if (keysym == 97)
        move_player(game, -1, 0);
    else if (keysym == 115)
        move_player(game, 0, 1);
    else if (keysym == 100)
        move_player(game, 1, 0);
    game->count++;
    printf("Movs: %d\n", game->count);
    return (0);
}
void move_player(t_game *game, int x, int y)
{
    int new_x;
    int new_y;

    new_x = game->player_x + x;
    new_y = game->player_y + y;

    if (game->map[new_y][new_x] == '1')
        return ;

    if (game->map[new_y][new_x] == 'C')
        game->c--;
    
    if (game->map[new_y][new_x] == 'E' && game->c == 0) 
        exit_game(game);
    if (game->map[new_y][new_x] == 'E' && game->c > 0)
        return ;
    game->map[game->player_y][game->player_x] = '0';
    game->map[new_y][new_x] = 'P';
    game->player_x = new_x;
    game->player_y = new_y;

    render_map(game);
}
