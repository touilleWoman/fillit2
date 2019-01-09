/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 13:18:30 by tlamart           #+#    #+#             */
/*   Updated: 2019/01/09 16:59:24 by tlamart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

int		error(void);
void	get_file(const int fd, char **file, t_list **tetri_lst);
void	create_tetri(int nb_tetri, char *file, t_list **tetri);
void	lst_put(t_list *elem);
int		solve(t_list *tetri_lst);
t_list	*lst_del(t_list *begin_lst, char *tetri);
void	put_tetri(char **square, int square_size, char *tetri, int end);
void	remove_tetri(char **square, char *tetri);
int		abs_t(char *square, char *tetri);
int		try(char *square, unsigned int square_size, char *tetri, int end);

#endif
