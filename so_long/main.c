/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmendes <anmendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:07:25 by anmendes          #+#    #+#             */
/*   Updated: 2025/04/05 16:25:42 by anmendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game  game;

    if(argc != 2)
        return (printf("Error\n"), 1);
    if (!ber_check(argv[1]))
    {
        printf("Error\nWrong type file\n");
        return (1);
    }
    init_game(&game, argv[1]);
}
int ber_check(char *argv)
{
    int i;

    i = 0;
    if (!argv)
        return (0);
    while (argv[i])
        i++;
    i--;
    if (argv[i] == 'r' && argv[i - 1] == 'e' && argv[i - 2] == 'b' && argv[i - 3] == '.')
        return (1);
    return (0);
}
