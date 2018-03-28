/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:49:20 by shagazi           #+#    #+#             */
/*   Updated: 2018/03/27 19:19:03 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main (int argc, char *argv[])
{
	int fd;
	char *str;
	int count;
	char **arr;
	int i;

	count = 0;
	i = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		str = return_string(fd);
		count = valid_file_check(str);
		arr = tetriminoarray(str, count);
		while (i < count)
		{
			tetriminocheck(arr[i]);
			tetriminoconvert(arr[i], i);
			i++;
		}
		close(fd);
	}
	else
		ft_putstr("Please enter file name.\n");
	return (0);
}
