/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:02:52 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/20 18:03:32 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memset(void *b, int c, size_t len)
{
	t_byte			*byte_ptr;

	byte_ptr = (t_byte *)b;
	while (len > 0)
	{
		*byte_ptr = (t_byte)c;
		++byte_ptr;
		--len;
	}
	return ((t_byte *)b);
}
