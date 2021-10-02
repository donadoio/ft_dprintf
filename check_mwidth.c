/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_mwidth.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 15:40:03 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/06 22:58:37 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	check_mwidth(const char *format, t_data *data)
{
	size_t	i;

	i = data->i;
	if (ft_isdigit(format[i]))
	{
		data->i_mwidth.i = i;
		while (ft_isdigit(format[i]))
			i++;
	}
	if (i != data->i)
	{
		data->mwidth = true;
		data->i = i;
	}
	return ;
}
