/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shagazi <shagazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:05:20 by shagazi           #+#    #+#             */
/*   Updated: 2018/03/27 19:19:02 by shagazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void set_args(int *i, int *j, int *k, int *n)
{
	*i = 0;
	*j = 0;
	*k = 0;
	*n = 0;
}

static void charcheck(char *str, int *j, int *k, int *n)
{
	if (*str == '#')
		(*j)++;
	if (*str == '.')
		(*k)++;
	if (*str == '\n')
		(*n)++;
}

/** checks to see if each section has the correct # of #'s, '.', and '\n'**/
int	valid_file_check(char *str)
{
	int i;
	int j;
	int k;
	int n;
	int count;

	set_args(&i, &j, &k, &n);
	count = 0;
	while (str[i] != '\0')
	{
		charcheck(str + i, &j, &k, &n);
		i++;
		if (i % 21 == 0 && i != 0)
		{
			if (j != 4 || k != 12 || n != 5)
			{
				ft_putstr("error");
				return (0);
			}
			else
			{
				j = 0;
				k = 0;
				n = 0;
				count++;
			}
		}
		if (str[i] == '\0' && j == 4 && k == 12 && n == 4)
			count++;
		if (str[i] == '\n' && str[i - 1] == '\n' && str[i + 1] == '\n')
		{
			ft_putstr("error");
			return (0);
		}
	}
	return (count);
}
