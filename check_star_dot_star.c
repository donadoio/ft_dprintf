/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_star_dot_star.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 17:32:13 by idonado       #+#    #+#                 */
/*   Updated: 2020/06/22 17:32:16 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	check_star_dot_star(char const *format, t_data *data)
{
	size_t	i;

	i = data->i;
	if (format[i] == '*' && format[i + 1] == '.' && format[i + 2] == '*')
	{
		data->i = data->i + 3;
		data->star_dot_star = true;
		data->check_combo = true;
		return ;
	}
	return ;
}
