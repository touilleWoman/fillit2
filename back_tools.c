/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:25:32 by tlamart           #+#    #+#             */
/*   Updated: 2019/01/09 17:06:02 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*lst_del(t_list *begin_lst, char *tetri)
{
	t_list	*lst;
	t_list	*prev;
	t_list	*next;

	if (ft_strequ(tetri, begin_lst->content))
	{
		next = begin_lst->next;
		ft_lstdelone(&begin_lst, &ft_lstdel_cnt);
		return (next);
	}
	prev = begin_lst;
	lst = prev->next;
	next = lst->next;
	while (lst)
	{
		if (ft_strequ(tetri, lst->content))
		{
			ft_lstdelone(&lst, &ft_lstdel_cnt);
			prev->next = next;
			return (begin_lst);
		}
		prev = lst;
		lst = next;
		next = lst->next;
	}
	return (NULL);
}

void	put_tetri(char **square, int square_size, char *tetri, int end)
{
	int		i;
	int		line;
	char	*sqr;

	i = 0;
	line = 0;
	sqr = *square;
	while (*tetri && *sqr && end)
	{
		if (ft_isalpha(*tetri))
		{
			sqr[i + line] = *tetri;
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

void	remove_tetri(char **square, char *tetri)
{
	char	*sqr;
	char	letter;

	sqr = *square;
	while (!ft_isalpha(*tetri))
		tetri++;
	letter = *tetri;
	while (*sqr)
	{
		if (*sqr == letter)
			*sqr = '.';
		sqr++;
	}
}

int		abs_t(char *square, char *tetri)
{
	char	letter;

	while (!ft_isalpha(*tetri))
		tetri++;
	letter = *tetri;
	while (*square && *square != letter)
		square++;
	return (*square != letter);
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
