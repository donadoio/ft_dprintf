/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_zeroes.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 18:39:50 by idonado       #+#    #+#                 */
/*   Updated: 2020/06/22 18:40:12 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	check_minus(const char *format, size_t i)
{
	while (format[i] == '-' || format[i] == '0')
		i++;
	return (i);
}

void	check_zeroes(const char *format, t_data *data)
{
	size_t	i;

	i = data->i;
	while (format[i] == '0')
		i++;
	if (data->i != i && format[i] == '.')
	{
		data->i = i - 1;
		return ;
	}
	else if (i != data->i)
	{
		data->zeroes = true;
		if (format[i] == '-')
		{
			data->left = true;
			i = check_minus(format, i);
		}
	}
	data->i = i;
	return ;
}
