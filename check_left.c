/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_left.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 19:10:57 by idonado       #+#    #+#                 */
/*   Updated: 2020/06/22 17:30:33 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	check_left_zeroes(const char *format, size_t i)
{
	while (format[i] == '-' || format[i] == '0')
		i++;
	if (format[i] == '0' && format[i + 1] == '.')
		i = i - 1;
	return (i);
}

void	check_left(const char *format, t_data *data)
{
	size_t	i;

	i = data->i;
	while (format[i] == '-')
		i++;
	if (i != data->i)
	{
		data->left = true;
		if (format[i] == '0' && format[i + 1] != '.')
		{
			data->zeroes = true;
			i = check_left_zeroes(format, i);
		}
	}
	data->i = i;
	return ;
}
