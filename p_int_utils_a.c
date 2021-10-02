/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_int_utils_a.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/21 20:58:30 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/06 22:56:57 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

t_vars	int_mwidth(t_data *data, t_vars vars)
{
	vars.min_width = vars.min_width - vars.str_width;
	while (vars.i < vars.min_width)
	{
		if (data->zeroes == true && data->left == false)
			vars.spaces = ft_chrjoin(vars.spaces, '0');
		else
			vars.spaces = ft_chrjoin(vars.spaces, ' ');
		vars.i++;
	}
	if (vars.is_negative == true && data->zeroes == true && data->left == false)
		vars.spaces = ft_chrrjoin('-', vars.spaces);
	else if (vars.is_negative == true && \
	(data->zeroes == false || data->left == true))
		vars.str = ft_chrrjoin('-', vars.str);
	if (data->left == true)
		vars.str = smart_join(vars.str, vars.spaces);
	else
		vars.str = smart_join(vars.spaces, vars.str);
	return (vars);
}

t_vars	int_dot_num(t_vars vars)
{
	vars.str_width = vars.precision - vars.str_width;
	while (vars.i < vars.str_width)
	{
		vars.spaces = ft_chrjoin(vars.spaces, '0');
		vars.i++;
	}
	if (vars.is_negative == true)
		vars.spaces = ft_chrrjoin('-', vars.spaces);
	vars.str = smart_join(vars.spaces, vars.str);
	return (vars);
}

t_vars	int_num_dot(t_data *data, t_vars vars)
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

t_vars	int_num_dot_num_b(t_vars vars)
{
	vars.str_width = vars.precision - vars.str_width;
	while (vars.i < vars.str_width)
	{
		vars.zeroes = ft_chrjoin(vars.zeroes, '0');
		vars.i++;
	}
	if (vars.is_negative == true)
		vars.zeroes = ft_chrrjoin('-', vars.zeroes);
	vars.str = seek_last_number(vars);
	vars.str = smart_join(vars.zeroes, vars.str);
	return (vars);
}

t_vars	int_num_dot_num_c(t_data *data, t_vars vars)
{
	vars.str_width = vars.min_width - vars.str_width;
	while (vars.i < vars.str_width)
	{
		p_int_util_a(&vars, data);
		vars.i++;
	}
	if (data->left == true)
		vars.str = smart_join(vars.str, vars.spaces);
	else
		vars.str = smart_join(vars.spaces, vars.str);
	if (vars.int_exception == true)
		vars.str[0] = '-';
	return (vars);
}
