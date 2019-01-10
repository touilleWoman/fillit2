/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 09:44:33 by tlamart           #+#    #+#             */
/*   Updated: 2019/01/10 12:19:54 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_tetri(char *square, int square_size, char *tetri)
{
	int		i;
	int		line;
	int		end;

	i = 0;
	end = 4;
	line = 0;
	while (*tetri && *square && end)
	{
		if (ft_isalpha(*tetri) == 1)
		{
			square[i + line] = *tetri;
			i++;
			end--;
		}
		else if (*tetri == '\n')
		{
			i = 0;
			line += square_size + 1;
		}
		else if (*tetri == '.')
			i++;
		tetri++;
	}
}

void	remove_tetri(char *square, char *tetri)
{
	char	letter;
	int		i;

	i = 0;
	while (!ft_isalpha(*tetri))
		tetri++;
	letter = *tetri;
	while (square[i])
	{
		if (square[i] == letter)
			square[i] = '.';
		i++;
	}
}

int		try(char *square, unsigned int square_size, char *tetri, int end)
{
	int		i;

	i = 0;
	while (*tetri && *square && end)
	{
		if (ft_isalpha(*tetri))
		{
			if (square[i] != '.')
				return (0);
			end--;
			i++;
		}
		else if (*tetri == '\n')
		{
			if (ft_strlen(square + i) < square_size)
				return (0);
			square += square_size + 1;
			i = 0;
		}
		else if (*tetri == '.')
			i++;
		tetri++;
	}
	return (!end);
}

int		backtracking(char **carre, int square_size, t_list *tetri)
{
	char	*square;

	square = *carre;
	if (!tetri)
		return (1);
	while (*square)
	{
		if (try(square, square_size, tetri->content, 4))
		{
			put_tetri(square, square_size, tetri->content);
			if (backtracking(carre, square_size, tetri->next))
				return (1);
			remove_tetri(square, tetri->content);
		}
		square++;
	}
	return (0);
}
