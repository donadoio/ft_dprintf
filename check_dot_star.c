/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_dot_star.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 16:24:29 by idonado       #+#    #+#                 */
/*   Updated: 2020/06/21 21:21:23 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	check_dot_star(const char *format, t_data *data)
{
	size_t	i;

	i = data->i;
	if (format[i] == '.')
	{
		if (format[i + 1] == '*')
		{
			data->i = data->i + 2;
			data->dot_star = true;
			data->check_combo = true;
			return ;
		}
	}
	return ;
}
