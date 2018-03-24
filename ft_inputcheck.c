/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputcheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 21:08:36 by shagazi           #+#    #+#             */
/*   Updated: 2018/03/23 23:30:48 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main (int argc, char *argv[])
{
	int fd;
	char buff[32];
	char *fileread;
	int retread;
	char *tmp;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Failed to open file. Please enter a file name.\n");
		exit(1);
	}
	fileread = ft_strnew(0);
	while ((retread = read(fd, buff, 32)))
	{
		buff[retread] = '\0';
		tmp = fileread;
		fileread = ft_strjoin(tmp, buff);
		free(tmp);
		if (retread == 0)
			ft_putstr("File has been read successfully.\n");
	}
	ft_putstr(fileread);
	ft_putstr("\n");
	close(fd);
}
