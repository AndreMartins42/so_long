#include "so_long.h"

int main(int argc, char **argv)
{
    t_game game;

    if(argc != 2)
        return (printf("Error\n"), 1);

    if (!ber_check(argv[1]))
    {
        printf("Wrong type file\n");
        return (1);
    }
    init_game(&game, argv[1]);
    mlx_loop(game.mlx);
}
int ber_check(char *argv)
{
    int i = 0;
    if (!argv)
        return (0);
    while (argv[i])
        i++;
    i--;
    if (argv[i] == 'r' && argv[i - 1] == 'e' && argv[i - 2] == 'b' && argv[i - 3] == '.') 
        return (1);
    return (0);
}
