/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:23:30 by tlamart           #+#    #+#             */
/*   Updated: 2019/01/09 15:09:59 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void	swap_line(char **str)
{
	int		i;
	char	*cast;

	i = 0;
	cast = *str;
	while (i < 14)
	{
		ft_swap(cast + i, cast + i + 5);
		i++;
	}
}

void	swap_column(char **str)
{
	int		i;
	char	*cast;

	i = 0;
	cast = *str;
	while (i < 18)
	{
		if (cast[i + 1] == '\n')
			i += 2;
		ft_swap(cast + i, cast + i + 1);
		i++;
	}
}

void	optimize_tetri(t_list **list)
{
	t_list	*tetri;
	char	*str;

	tetri = *list;
	while (tetri)
	{
		str = tetri->content;
		while (str[0] == '.' && str[1] == '.'\
				&& str[2] == '.' && str[3] == '.')
			swap_line(&str);
		while (str[0] == '.' && str[5] == '.'\
				&& str[10] == '.' && str[15] == '.')
			swap_column(&str);
		tetri = tetri->next;
	}
}

void	optimize_more(t_list **list)
{
	t_list	*tetri;
	char	*str;
	int		line;

	tetri = *list;
	while (tetri)
	{
		line = 0;
		str = tetri->content;
		while (line < 4 && *str)
		{
			while (*str == '.' && *str)
				str++;
			while (ft_isalpha(*str))
				str++;
			while (*str == '.' && *str)
			{
				*str = '0';
				str++;
			}
			str++;
			line++;
		}
		tetri = tetri->next;
	}
}

void	create_tetri(int nb_tetri, char *file, t_list **tetri)
{
	t_list	*new;
	char	*str;
	char	letter;

	if (!(*tetri = ft_lstset("....\n....\n....\n....\n\n", 22, nb_tetri)))
		return ;
	new = *tetri;
	letter = 'A';
	while (new)
	{
		str = new->content;
		while (*str)
		{
			if (*file == '#')
				*str = letter;
			file++;
			str++;
		}
		letter++;
		new = new->next;
	}
	optimize_tetri(tetri);
	optimize_more(tetri);
}
