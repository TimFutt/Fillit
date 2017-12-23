/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:56:17 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/30 15:56:19 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int number)
{
	size_t len;

	len = 0;
	if (number < 0)
		++len;
	else
		number = -number;
	while (number < 0)
	{
		number /= 10;
		++len;
	}
	return (len);
}

static int		create_string(int value, int base, char **end)
{
	int		tmp_value;
	char	*base_array;

	base_array = "zyxwvutsrqponmlkjihgfedcba9876543210\
				123456789abcdefghijklmnopqrstuvwxyz";
	tmp_value = value;
	value /= base;
	**end++ = base_array[35 + (tmp_value - value * base)];
	while (value)
	{
		tmp_value = value;
		value /= base;
		**end++ = base_array[35 + (tmp_value - value * base)];
	}
	return (tmp_value);
}

char			*ft_itoa_base(int value, int base)
{
	char	*end;
	char	*start;
	char	*result;
	char	tmp_char;
	int		sign;

	if ((result = (char *)malloc(sizeof(*result) * (get_len(value) + 1)))
			== NULL)
		return (NULL);
	end = result;
	start = result;
	if (base < 2 || base > 36)
		return (NULL);
	sign = create_string(value, base, &end);
	if (sign < 0)
		*end++ = '-';
	*end-- = '\0';
	while (start < end)
	{
		tmp_char = *end;
		*end-- = *start;
		*start++ = tmp_char;
	}
	return (result);
}
