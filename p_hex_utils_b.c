/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_hex_utils_b.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 21:35:37 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/06 23:54:48 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

t_vars	hex_double_precision(t_vars vars)
{
	vars.str_width = vars.precision - vars.str_width;
	vars.zeroes = ft_strdup("");
	while (vars.i < vars.str_width)
	{
		vars.zeroes = ft_chrjoin(vars.zeroes, '0');
		vars.i++;
	}
	vars.str = smart_join(vars.zeroes, vars.str);
	return (vars);
}

t_vars	hex_double_mwidth(t_data *data, t_vars vars)
{
	vars.str_width = vars.min_width - vars.str_width;
	vars.spaces = ft_strdup("");
	while (vars.i < vars.str_width)
	{
		if ((data->zeroes == true && data->left == false && vars.precision == 0 \
		&& vars.unumber != 0 && vars.hex_exception == false) || \
		(data->zeroes == true && data->left == false && \
		vars.negative_prec == true))
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

t_vars	hex_mwidth(t_data *data, t_vars vars)
{
	vars.str_width = vars.min_width - vars.str_width;
	vars.spaces = ft_strdup("");
	while (vars.i < vars.str_width)
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

t_vars	hex_dn(t_vars vars)
{
	vars.str_width = vars.precision - vars.str_width;
	vars.spaces = ft_strdup("");
	while (vars.i < vars.str_width)
	{
		vars.spaces = ft_chrjoin(vars.spaces, '0');
		vars.i++;
	}
	vars.str = smart_join(vars.spaces, vars.str);
	return (vars);
}

t_vars	hex_nd(t_data *data, t_vars vars)
{
	vars.spaces = ft_strdup("");
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
