/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_all.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 16:48:05 by idonado       #+#    #+#                 */
/*   Updated: 2020/06/21 20:15:47 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	check_all(t_data *data)
{
	if (data->left == true || data->zeroes == true)
		return (1);
	else if (data->mwidth == true || data->num_dot == true)
		return (1);
	else if (data->num_dot_num == true || data->num_dot_star)
		return (1);
	else if (data->star == true || data->star_dot == true)
		return (1);
	else if (data->star_dot_num == true || data->star_dot_star)
		return (1);
	else if (data->dot || data->dot_num || data->dot_star)
		return (1);
	return (0);
}
