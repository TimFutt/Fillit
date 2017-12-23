/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:08:05 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/08 17:27:57 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** \brief    Fast Square root algorithm, with rounding
**
** The second highest bit is set in variable "mask".
** We need "mask" to start at the highest power of four inferior or equal
** to the argument.
** See "https://en.wikipedia.org/wiki/Methods_of_computing_square_roots
**       #Binary_numeral_system_.28base_2.29" for an explanation.
**
** This does arithmetic rounding of the resultult. That is, if the real answer
** would have a fractional part of 0.5 or greater, the resultult is rounded up
** to the next integer.
*/

uint32_t	ft_sqrt(uint32_t nb)
{
	uint32_t i;

	i = 0;
	while (i * i < nb)
		++i;
	return (i);
}
