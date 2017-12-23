/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:04:50 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/08 14:22:53 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_INPUT_H
# define UTILS_INPUT_H

# include "fillit.h"

t_point		*new_point(int x, int y);
t_list		*free_list(t_list *list);
void		get_min_max(char *str, t_point *min, t_point *max);

#endif
