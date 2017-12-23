/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:02:39 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/08 14:32:53 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "algorithm.h"
#include "input.h"
#include "map.h"
#include "output.h"

int		main(int argc, char **argv)
{
	t_list		*list;
	t_map		map;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	if ((list = reading_tetri(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	map.map = NULL;
	map.size = get_map_minsize(list);
	while (1)
	{
		create_map(&map);
		if (solve_map(list, &map) == SUCCESS)
			break ;
		map.size += 1;
	}
	print_map(map, list);
	free(map.map);
	return (SUCCESS);
}
