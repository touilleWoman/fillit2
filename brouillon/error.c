/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:32:39 by tlamart           #+#    #+#             */
/*   Updated: 2019/01/02 16:58:14 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error_int(void)
{
	ft_putendl_fd("error", 2);
	return (0);
}

void	*ft_error_ptr(void)
{
	ft_putendl_fd("error", 2);
	return (NULL);
}

int		ft_usage(int nb)
{
	if (nb < 2)
		ft_putendl_fd("fillit: file path is missing", 2);
	else if (nb > 2)
		ft_putendl_fd("fillit: too many parameters", 2);
	return (0);
}
