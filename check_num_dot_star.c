/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_num_dot_star.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 18:45:50 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/06 22:59:32 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
void	check_num_dot_star(const char *format, t_data *data)
{
	size_t	i;

	i = data->i;
	if (!ft_isdigit(format[i]))
		return ;
	if (ft_isdigit(format[i]))
		data->i_num_dot_star.i = i;
	while (ft_isdigit(format[i]))
		i++;
	if (format[i] == '.' && format[i + 1] == '*')
	{
		data->i = i + 2;
		data->num_dot_star = true;
		data->check_combo = true;
		return ;
	}
	return ;
}
