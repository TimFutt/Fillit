/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:46:19 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/23 13:13:34 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "fillit.h"
# include "map.h"

t_bool	place_tetri(t_tetri *tetri, t_map *map, uint32_t x, uint32_t y);
t_bool	solve_map(t_list *list, t_map *map);

#endif
