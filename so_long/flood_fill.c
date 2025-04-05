/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:13:40 by anmendes          #+#    #+#             */
/*   Updated: 2025/04/05 16:26:40 by anmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, int x, int y)
{
	if (game->player_x < 0 || game->player_y < 0 || !game->map_cpy[y] || !game->map_cpy[y][x])
		return ;
	if (game->map_cpy[y][x] == '1' || game->map_cpy[y][x] == 'V')
		return ;
	game->map_cpy[y][x] = 'V';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

int	ft_validate_map_flood_fill(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map_cpy[++i])
	{
		j = 0;
		while (game->map_cpy[i][j])
		{
			if (game->map_cpy[i][j] == '1' || game->map_cpy[i][j] == 'V')
				j++;
			else
				return (1);
		}
	}
	return (0);
}

char	**copy_map(char **map, int height)
{
	char	**map_copy;
	int		i;

	map_copy = malloc((height + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}
