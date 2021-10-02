/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_uint_utils_a.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 17:35:00 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/06 22:55:31 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

t_vars	uint_mwidth(t_data *data, t_vars vars)
{
	while (vars.i < vars.min_width)
	{
		if (data->zeroes == true && data->left == false)
			vars.spaces = ft_chrjoin(vars.spaces, '0');
		else
			vars.spaces = ft_chrjoin(vars.spaces, ' ');
		vars.i++;
	}
	if (data->left == true)
		vars.str = smart_join(vars.str, vars.spaces);
	else
		vars.str = smart_join(vars.spaces, vars.str);
	return (vars);
}

t_vars	uint_dot_num(t_vars vars)
{
	vars.str_width = vars.precision - vars.str_width;
	while (vars.i < vars.str_width)
	{
		vars.spaces = ft_chrjoin(vars.spaces, '0');
		vars.i++;
	}
	vars.str = smart_join(vars.spaces, vars.str);
	return (vars);
}

t_vars	uint_num_dot(t_data *data, t_vars vars)
{
	vars.str_width = vars.min_width - vars.str_width;
	while (vars.i < vars.str_width)
	{
		vars.spaces = ft_chrjoin(vars.spaces, ' ');
		vars.i++;
	}
	if (data->left == true)
		vars.str = smart_join(vars.str, vars.spaces);
	else
		vars.str = smart_join(vars.spaces, vars.str);
	return (vars);
}

t_vars	uint_num_dot_num(t_vars vars)
{
	vars.str_width = vars.precision - vars.str_width;
	while (vars.i < vars.str_width)
	{
		vars.zeroes = ft_chrjoin(vars.zeroes, '0');
		vars.i++;
	}
	vars.str = smart_join(vars.zeroes, vars.str);
	return (vars);
}

t_vars	uint_num_dot_num_a(t_vars vars)
{
	if (vars.unumber == 0)
		vars.str = ft_strdup("");
	else
		vars.str = ft_itoa_unsigned(vars.unumber);
	if (vars.str == NULL)
		vars.print_fail = true;
	vars.str_width = ft_strlen(vars.str);
	if (vars.str_width < vars.precision)
	{
		vars.zeroes = ft_strdup("");
		if (vars.zeroes == NULL)
			vars.print_fail = true;
		vars = uint_num_dot_num(vars);
		if (vars.str == NULL)
			vars.print_fail = true;
	}
	vars.str_width = ft_strlen(vars.str);
	vars.i = 0;
	return (vars);
}
