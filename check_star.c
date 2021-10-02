/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_star.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 18:39:37 by idonado       #+#    #+#                 */
/*   Updated: 2020/06/22 18:39:39 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	check_star(const char *format, t_data *data)
{
	size_t	i;

	i = data->i;
	if (format[i] == '*')
	{
		if (format[i + 1] != '.')
		{
			data->star = true;
			data->check_combo = true;
			data->i = data->i + 1;
			return ;
		}
	}
	return ;
}
