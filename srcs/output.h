/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:34:53 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/08 14:24:15 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H

# include "fillit.h"

void	initialize_map(char **map_ptr, uint8_t size);
void	print_map(t_map map, t_list *list);

#endif
