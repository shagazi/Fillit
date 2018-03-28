/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputcheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 21:08:36 by shagazi           #+#    #+#             */
/*   Updated: 2018/03/27 19:18:59 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*** assigns the string in the file to a char pointer ***/
char *return_string(int fd)
{
	char	buff[32];
	char	*fileread;
	int		retread;
	char	*tmp;

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

/* Create a function that copies the string created from return_string,
and insert each tetrimino into an array of size (5 columns and 4 rows).
Function should return each tetriminio into a 2d array.
*/
char	**tetriminoarray(char *str, int count)
{
	char	**arr;
	int		k;
	int		t;

	k = 0;
	t = 0;
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	while (str[t] != '\0')
	{
		arr[k] = ft_strnew(21);
		ft_strncpy(arr[k], &str[t], 21);
		k++;
		t += 21;
	}
	//arr = NULL; see what happens after we run checker
	return (arr);
}

/* Checks to see if the shape passed is a valid tetrimino piece */
int tetriminocheck(char *arr)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] == '#')
		{
			if ((i < 21 && arr[i + 1] == '#') || (i > 0 && arr[i - 1] == '#') ||
				(i <= 16 && arr[i + 5] == '#') || (i >= 5 && arr[i - 5] == '#'))
				count++;
		}
		i++;
	}
	if (count == 4)
		return (1);
	return (0);
}

/* Converts "#" to Alpha*/
char tetriminoconvert(char *arr, int alphaiter)
{
	int		i;
	char	alpha;

	i = 0;
	alpha = 65 + alphaiter;
	while (arr[i] != '\0')
	{
		if (alphaiter <= 26)
		{
			if (arr[i] == '#')
				arr[i] = alpha;
			ft_putchar(arr[i]);
		}
		i++;
	}
	return (0);
}
