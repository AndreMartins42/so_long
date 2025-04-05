/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:05:26 by anmendes          #+#    #+#             */
/*   Updated: 2025/04/05 16:33:05 by anmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_player_count(t_game	*game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
			{
				game->p++;
				game->player_y = i;
				game->player_x = j;
			}
			else if (game->map[i][j] == 'C')
				game->c++;
			else if (game->map[i][j] == 'E')
				game->e++;
		}
	}
	if (game->p == 1 && game->c > 0 && game->e == 1)
		return (1);
	return (0); 
}

int	validate_map_elements(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (ft_validate_char(game->map[i][j]) == 1)
				return (1);
		}
	}
	return (0);
}
