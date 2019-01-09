/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:31:13 by tlamart           #+#    #+#             */
/*   Updated: 2019/01/08 19:22:58 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	lstprint(t_list *list)
{
	ft_putstr(list->content);
}

int		main(int ac, char **av)
{
	char	*file;
	int		ret;
	t_list	*lst_tetri;

	if (ac != 2)
		return (ft_usage(ac));
	if (!(file = ft_strnew(1023)))
		return (ft_error_int());
	if (!(ret = get_file(av[1], &file)) || !(check_file(file)) ||\
		!(create_tetri(ret / 21, file, &lst_tetri)))
	{
		ft_strdel(&file);
		return (ft_error_int());
	}
	ft_strdel(&file);
	if (!(fillit(lst_tetri, (ret / 21))))
	{
		ft_lstdel(&lst_tetri, &ft_lstdel_cnt);
		return (ft_error_int());
	}
	ft_lstdel(&lst_tetri, &ft_lstdel_cnt);
	return (0);
}
