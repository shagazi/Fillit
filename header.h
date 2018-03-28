/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 21:27:47 by shagazi           #+#    #+#             */
/*   Updated: 2018/03/27 19:18:18 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"


char 	*return_string(int fd);
int 	valid_file_check(char *str);
char 	**tetriminoarray(char *str, int count);
int 	tetriminocheck(char *arr);
char 	tetriminoconvert(char *arr, int alphaiter);



# endif
