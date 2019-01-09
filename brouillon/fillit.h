/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:09:45 by tlamart           #+#    #+#             */
/*   Updated: 2019/01/08 17:11:25 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include ".libft/libft.h"
# include <stdio.h> //delete later

int		get_file(char *file_path, char **file);
int		ft_error_int(void);
void	*ft_error_ptr(void);
int		ft_usage(int nb);
int		check_line(char *line);
int		check_file(char *file);
int		create_tetri(int nb_tetri, char *file, t_list **tetri);
int		fillit(t_list *tetri_lst, int tetri_nbr);
int		backtracking(char **carre, int square_size, t_list *tetri);

#endif
