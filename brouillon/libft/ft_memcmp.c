/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 15:06:11 by tlamart           #+#    #+#             */
/*   Updated: 2018/11/21 16:06:12 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cast_s1;
	const unsigned char	*cast_s2;

	cast_s1 = s1;
	cast_s2 = s2;
	if (n == 0)
		return (0);
	else if (*cast_s1 == *cast_s2)
		return (ft_memcmp(++s1, ++s2, --n));
	else
		return (*cast_s1 - *cast_s2);
}
