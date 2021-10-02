/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_star_dot.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 18:46:14 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/06 22:58:21 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	check_star_dot(const char *format, t_data *data)
{
	size_t	i;

	i = data->i;
	if (format[i] == '*' && format[i + 1] == '.')
	{
		if (format[i + 2] != '*' && !ft_isdigit(format[i + 2]))
		{
			data->star_dot = true;
			data->check_combo = true;
			data->i = data->i + 2;
			return ;
		}
	}
	return ;
}
