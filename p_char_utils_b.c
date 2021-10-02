/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_char_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 15:16:32 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/06 22:57:37 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	p_char_util_a(t_vars *vars, t_data *data)
{
	if (data->zeroes == true && data->left == false)
		vars->spaces = ft_chrjoin(vars->spaces, '0');
	else
		vars->spaces = ft_chrjoin(vars->spaces, ' ');
	return ;
}
