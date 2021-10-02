/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_ptr_utils_e.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 16:27:18 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/07 00:38:56 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	p_ptr_util_a(t_vars *vars)
{
	if (vars->ulnumber == 0)
		vars->str_width = ft_strlen(vars->ptr);
	else
		vars->str_width = ft_strlen(vars->str) + 2;
	return ;
}
