#include "so_long.h"

int	ft_read_map(t_game *game, char *file_path)
{
	int		i;
    int 	fd;
	char	*line;
	size_t	len;

    fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (close(fd), 1);
	game->map = malloc((game->height + 1) * (sizeof(char *)));
	if (!game->map)
		return (1);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		game->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	return (close(fd), 0);
}

void ft_map_height(t_game *game, char *file_path)
{
    int fd;
    char *line;

    fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return ;
    game->height = 0;
    line = get_next_line(fd);
    while (line)
    {
        game->height++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
}

int ft_map_width(t_game *game)
{
	int i;

	game->width = ft_strlen(game->map[0]);
	i = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != game->width)
			return (0);
		i++;
	}
	return (1);
}

int	ft_validate_char(char c)
{
	if (c == 'P' || c == 'C' || c == 'E' || c == '1' || c == '0')
		return (0);
	return (1);
}
int    ft_map_wall(t_game *game)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (game->map[i])
		i++;
	while (game->map[0][j] && game->map[i - 1][j] != '\0')
	{
		if (game->map[0][j] != '1' || game->map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	len = ft_strlen(game->map[i]);
	while (game->map[i])
	{
		if (game->map[i][0] != '1' || game->map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}