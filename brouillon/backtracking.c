/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 09:44:33 by tlamart           #+#    #+#             */
/*   Updated: 2019/01/08 19:31:50 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include ".libft/libft.h"

int		finish(char *square, t_list *tetri_lst)
{
	char	letter;
	int		i;
	char	*tetri;

	while (tetri_lst)
	{
		i = 0;
		tetri = (char*)tetri_lst->content;
		while (!ft_isalpha(*tetri))
			tetri++;
		letter = *tetri;
		while (square[i] && square[i] != letter)
			i++;
		if (square[i] != letter)
			return (0);
		tetri_lst = tetri_lst->next;
	}
	return (1);
}

int		tetri_absent(char *square, char *tetri)
{
	char	letter;

	while (!ft_isalpha(*tetri))
		tetri++;
	letter = *tetri;
	while (*square && *square != letter)
		square++;
	return (*square != letter);
}

void	*put_tetri(char *square, int square_size, char *tetri)
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
		else if (*tetri == '.' && ft_isalpha(*(tetri + 1)))
			i++;
		tetri++;
	}
	return (square);
}

char	*remove_tetri(char *square, char *tetri)
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
	return (square);
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
		else if (*tetri == '.' && (ft_isalpha(*(tetri + 1))))
			i++;
		tetri++;
	}
	return (!end);
}

int		backtracking(char **carre, int square_size, t_list *tetri_lst)
{
	t_list	*tetri;
	char	*square;

	square = *carre;
	if (finish(square, tetri_lst))
		return (1);
	tetri = tetri_lst;
	while (*square)
	{
		while (*square && *square != '.')
			square++;
		while (tetri && *square)
		{
			if (tetri_absent(square, tetri->content) &&\
				try(square, square_size, tetri->content, 4))
			{
				square = put_tetri(square, square_size, tetri->content);
				if (backtracking(carre, square_size, tetri_lst))
					return (1);
				square = remove_tetri(square, tetri->content);
			}
			tetri = tetri->next;
		}
		tetri = tetri_lst;
		square++;
	}
	return (0);
}
