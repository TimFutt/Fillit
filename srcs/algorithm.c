/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:39:35 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/08 13:32:32 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

/*
** 1- try to place tetri inside the smallest map, everytime using the up-left
** corner
** 3- The first solution found has to be the one with all the pieces in the top
** left corner.
** 2- If there are no solution, return failure.
**
** x + width <= to size because if we have a width of 2, it can go in a map
** size 2
*/

t_bool	solve_map(t_list *list, t_map *map)
{
	uint32_t	x;
	uint32_t	y;
	t_tetri		*tetri;

	if (list == NULL)
		return (SUCCESS);
	tetri = (t_tetri *)list->content;
	y = -1;
	while (++y + tetri->length <= map->size)
	{
		x = -1;
		while (++x + tetri->width <= map->size)
		{
			if (check_map(*tetri, *map, x, y) == SUCCESS)
			{
				place_on_map(tetri, map, x, y);
				if (solve_map(list->next, map) == SUCCESS)
					return (SUCCESS);
				else
					place_on_map(tetri, map, x, y);
			}
		}
	}
	return (FAILURE);
}
