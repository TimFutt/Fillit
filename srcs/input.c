/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:31:04 by tifuret           #+#    #+#             */
/*   Updated: 2017/12/23 13:13:43 by tifuret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "input.h"

/*
** Creates a new tetrimino structure.
** Convert a tab of char to a tab of int to store the tetri
** Bit shift = j - (tetri_size - width)
*/

static t_tetri		*tetris_new(char *piece[TETRI_SIZE],
		int width, int length, char rank)
{
	uint8_t		i;
	uint8_t		j;
	uint32_t	offset;
	t_tetri		*tetri;

	tetri = ft_memalloc(sizeof(t_tetri));
	i = -1;
	while (++i < TETRI_SIZE)
		tetri->tetriminos[i] = 0;
	i = -1;
	while (++i < length)
	{
		j = -1;
		while (++j < width)
			if (piece[i][j] == '#')
			{
				offset = (width - 1) - j;
				tetri->tetriminos[i] ^= (1u << offset);
			}
	}
	tetri->width = width;
	tetri->length = length;
	tetri->rank = rank;
	return (tetri);
}

/*
** Reads a piece from a valid chunk, allocates a structure and populates it.
*/

static t_tetri		*get_piece(char *str, char piece)
{
	t_point		*min;
	t_point		*max;
	t_tetri		*tetri;
	char		*tetri_tab[TETRI_SIZE];
	int			i;

	min = new_point(3, 3);
	max = new_point(0, 0);
	i = 0;
	get_min_max(str, min, max);
	while (i < (max->y - min->y + 1))
	{
		tetri_tab[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(tetri_tab[i], str + (min->x) + (i + min->y) * 5,
				max->x - min->x + 1);
		i++;
	}
	tetri = tetris_new(tetri_tab, (max->x - min->x + 1),
						(max->y - min->y + 1), piece);
	free(min);
	free(max);
	return (tetri);
}

/*
** Checks connection counts, if we have 6 or 8 connections, the tetrimino is
** valid. Otherwise, our tetrimino is not contiguous.
*/

static int			check_connections(char *str)
{
	int		block;
	int		i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}

/*
** Checks character counts and that chunk format is valid.
** 1- We check if there are other chars than '#' or '.'
** 2- If there is a '#' we increment block to check if there are more than 4 '#'
** 3- If there is no '\n' at the end of the 4 chars, the string is bad.
** 4- For the 21st char, we check if it is a newline
** 5- Then we check if the tetris block are all connected.
*/

static int			check_input_string(char *str, int count)
{
	int		i;
	int		block;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (FAILURE);
			if (str[i] == '#' && ++block > 4)
				return (FAILURE);
		}
		else if (str[i] != '\n')
			return (FAILURE);
		i++;
	}
	if (count == TETRI_STRING && str[20] != '\n')
		return (FAILURE);
	if (!check_connections(str))
		return (FAILURE);
	if (count == TETRI_STRING && str[20] == '\n')
		return (NEWLINE);
	return (SUCCESS);
}

/*
** Read tetriminos from fd and put them in a list.
** We use 21 sized reads to read piece by piece since there are
** 4 lines made of 4 chars (+ newline) = 20 chars + newline = 21 chars
*/

t_list				*reading_tetri(int fd)
{
	char			*tetri_tmp;
	t_checktetri	check;
	char			rank;
	t_list			*list;
	t_tetri			*tetris;

	tetri_tmp = ft_strnew(21);
	list = NULL;
	rank = 'A';
	while ((check.read = read(fd, tetri_tmp, TETRI_STRING)) >= 20)
	{
		if ((check.nl = check_input_string(tetri_tmp, check.read)) == FAILURE
			|| rank > 'Z' || (tetris = get_piece(tetri_tmp, rank++)) == NULL)
		{
			free(tetri_tmp);
			return (free_list(list));
		}
		ft_lstappend(&list, ft_lstnew(tetris, sizeof(t_tetri)));
		free(tetris);
	}
	free(tetri_tmp);
	if ((check.read == 0 && check.nl == NEWLINE) || (check.read != 0))
		return (free_list(list));
	return (list);
}
