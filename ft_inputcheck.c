/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputcheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 21:08:36 by shagazi           #+#    #+#             */
/*   Updated: 2018/03/24 02:48:54 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char *return_string(int fd)
{
	char buff[32];
	char *fileread;
	int retread;
	char *tmp;

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
	}
	return (fileread);
}

char valid_file_check(char *str)
{
	int i;
	int j; //hashtag
	int k; //periods
	int n; //newline

	i = 0;
	j = 0;
	k = 0;
	n = 0;
	while (str[i] != '\0')
	{

		if (str[i] == '#')
			j++;
		if (str[i] == '.')
			k++;
		if (str[i] == '\n')
			n++;
		ft_putchar(str[i]);
		i++;
		if (i % 21 == 0 && i != 0)
		{
			if (j != 4 || k != 12 || n != 5)
			{
				ft_putstr("1st error");
				ft_putnbr(i);
				ft_putnbr(j);
				ft_putnbr(k);
				ft_putnbr(n);
				return (0);
			}
			else
			{
				j = 0;
				k = 0;
				n = 0;
			}
		}
		if (str[i] == '\n' && str[i + 1] == '\n' && str [i + 2] == '\n')
		{
			ft_putstr("2nd error");
			return (0);
		}
	}
	return (0);
}

int main (int argc, char *argv[])
{
	int fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		valid_file_check(return_string(fd));
		close(fd);
	}
	else
		ft_putstr("Please enter file name.\n");
	return (0);
}
