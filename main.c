/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 10:14:55 by tlamart           #+#    #+#             */
/*   Updated: 2019/01/09 17:09:57 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include "fcntl.h"
#include "unistd.h"

void	lst_put(t_list *elem)
{
	ft_putstr(elem->content);
}

int		fillit(const int fd)
{
	char	*file;
	t_list	*tetri_lst;

	get_file(fd, &file, &tetri_lst);
	solve(tetri_lst);
	ft_lstdel(&tetri_lst, &ft_lstdel_cnt);
	return (0);
}

int		usage(int nb_params)
{
	ft_putendl_fd("usage: ./fillit file", 2);
	return (0);
}

int		error(void)
{
	ft_putendl_fd("error", 2);
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
		return (usage(ac));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (error());
	fillit(fd);
	close(fd);
	return (1);
}
