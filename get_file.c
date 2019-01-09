/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:07:30 by tlamart           #+#    #+#             */
/*   Updated: 2019/01/09 14:29:56 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <unistd.h>

int		check_around(char *tetri, int i)
{
	if (i < 5)
	{
		if (i == 0)
			return ((tetri[i + 1] == '#') + (tetri[i + 5] == '#'));
		return ((tetri[i - 1] == '#') + (tetri[i + 1] == '#')\
				+ (tetri[i + 5] == '#'));
	}
	else if (i >= 15)
		return ((tetri[i - 5] == '#') + (tetri[i - 1] == '#')\
				+ (tetri[i + 1] == '#'));
	else
		return ((tetri[i - 5] == '#') + (tetri[i - 1] == '#') +\
				(tetri[i + 1] == '#') + (tetri[i + 5] == '#'));
}

int		check_tetri(char *tetri)
{
	int		i;
	int		nb_square;
	int		touch;

	i = 0;
	nb_square = 0;
	touch = 0;
	while (i < 20)
	{
		if (tetri[i] == '#')
		{
			touch += check_around(tetri, i);
			nb_square++;
		}
		i++;
	}
	if (nb_square == 4 && touch >= 6)
		return (1);
	return (0);
}

int		check_line(char *line)
{
	int		len;

	if (!line)
		return (0);
	len = 0;
	while (*line && (*line == '.' || *line == '#') && len < 4)
	{
		len++;
		line++;
	}
	if (len == 4 && *line == '\n')
		return (1);
	return (0);
}

int		verif_file(char *file)
{
	int		nb_line;

	nb_line = 0;
	while (check_line(file))
	{
		file = ft_strchr(file, '\n') + 1;
		nb_line++;
		if (nb_line == 4)
		{
			if (!check_tetri(file - 20))
				return (0);
			nb_line = 0;
			if (*file == '\n')
				file++;
			else if (*file == '\0')
				return (1);
			else
				return (0);
		}
	}
	return (0);
}

void	get_file(const int fd, char **file, t_list **tetri_lst)
{
	int		ret;
	char	*tmp;

	if (!(*file = ft_strnew(1024)))
		return ;
	tmp = *file;
	ret = read(fd, *file, 1024);
	if (ret < 20 || ret > 546 || (ret + 1) % 21 != 0 || !(verif_file(*file)))
	{
		ft_strdel(&tmp);
		*file = NULL;
		return ;
	}
	create_tetri((ret + 1) / 21, *file, tetri_lst);
	ft_strdel(&tmp);
	*file = NULL;
}
