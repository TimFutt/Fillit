/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:23:23 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/08 14:43:30 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output.h"

/*
** We need to initialize the map with '.' and '\n' for every printed lines
*/

void				initialize_map(char **map_ptr, uint8_t size)
{
	size_t	i;

	ft_memset(*map_ptr, '.', (size * (size + 1)));
	i = 1;
	while (i <= size)
	{
		(*map_ptr)[(i * (size + 1)) - 1] = '\n';
		++i;
	}
}

/*
** We mask the tetri at the coordinate we need to print.
** If we get a positive number, we write the letter.
** We calculate the coordinates using the coordinates of the tetri, and add an
** offset because we write in a 1D string.
** [(y + i) * (size + 1) - 1] places us at the end of the line. we need to
** remove 1 because we start counting at 0.
** Now we have to remove some to get to the place where we want to put our tetri
*/

static void			print_tetri(t_tetri tetri, uint8_t size, char **map_str)
{
	uint8_t		i;
	uint8_t		j;
	uint32_t	new_line;
	uint32_t	tetri_offset;
	uint32_t	map_index;

	i = 1;
	while (i <= tetri.length)
	{
		j = 0;
		while (j < tetri.width)
		{
			if (0x01 & (tetri.tetriminos[i - 1] >> j))
			{
				new_line = (tetri.y + i) * (size + 1);
				tetri_offset = size - (tetri.x + tetri.width) + j;
				map_index = new_line - tetri_offset - 2;
				(*map_str)[map_index] = tetri.rank;
			}
			++j;
		}
		++i;
	}
}

/*
** We create a string that is big enough to store all the tetris, and the \n
** that we will use to print the map.
** Then we print all tetris in this string by replacing the default character by
** the corresponding rank character in the structure.
*/

void				print_map(t_map map, t_list *list)
{
	char	*map_string;

	if (list == NULL || list->content == NULL)
		return ;
	if ((map_string = ft_strnew(map.size * (map.size + 1))) == NULL)
		return ;
	initialize_map(&map_string, map.size);
	while (list != NULL)
	{
		print_tetri((t_tetri)*(t_tetri *)(list->content), map.size,
				&map_string);
		list = list->next;
	}
	ft_putstr(map_string);
	free(map_string);
}
