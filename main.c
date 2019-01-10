/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:31:13 by tlamart           #+#    #+#             */
/*   Updated: 2019/01/10 13:33:21 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		usage(void)
{
	ft_putendl("usage: ./fillit file");
	return (0);
}

int		error(void)
{
	ft_putendl("error");
	return (0);
}

int		main(int ac, char **av)
{
	char	*file;
	int		ret;
	t_list	*lst_tetri;

	if (ac != 2)
		return (usage());
	if (!(file = ft_strnew(1024)))
		return (error());
	if (!(ret = get_file(av[1], &file)) || !(check_file(file)) ||\
		!(create_tetri(ret / 21, file, &lst_tetri)))
	{
		ft_strdel(&file);
		return (error());
	}
	ft_strdel(&file);
	if (!(fillit(lst_tetri, ret / 21)))
	{
		ft_lstdel(&lst_tetri, &ft_lstdel_cnt);
		return (error());
	}
	ft_lstdel(&lst_tetri, &ft_lstdel_cnt);
	return (0);
}
