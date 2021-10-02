/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_ptr_utils_a.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/28 17:06:46 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/07 00:40:45 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

t_vars	ptr_mwidth(t_data *data, t_vars vars)
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
	vars = ptr_mwidth_if(vars, data);
	return (vars);
}

t_vars	ptr_dot_num(t_vars vars)
{
	vars.str_width = vars.precision - vars.str_width;
	vars.zeroes = ft_strdup("");
	while (vars.i < vars.str_width)
	{
		vars.zeroes = ft_chrjoin(vars.zeroes, '0');
		vars.i++;
	}
	vars.str = smart_join(vars.zeroes, vars.str);
	vars.str = smart_join(vars.ptr, vars.str);
	return (vars);
}

t_vars	ptr_double_precision(t_vars vars)
{
	vars.str_width = vars.precision - vars.str_width;
	vars.zeroes = ft_strdup("");
	while (vars.i < vars.str_width)
	{
		vars.zeroes = ft_chrjoin(vars.zeroes, '0');
		vars.i++;
	}
	vars.str = smart_join(vars.zeroes, vars.str);
	vars.str = smart_join(vars.ptr, vars.str);
	if (vars.str != NULL)
		vars.ptr_trigger = 1;
	return (vars);
}

t_vars	ptr_double_mwidth(t_data *data, t_vars vars)
{
	vars.i = 0;
	if (vars.ptr_trigger == 0)
		vars.str = smart_join(vars.ptr, vars.str);
	if (vars.str != NULL)
		vars.str_width = ft_strlen(vars.str);
	vars.str_width = vars.min_width - vars.str_width;
	vars.spaces = ft_strdup("");
	while (vars.i < vars.str_width)
	{
		vars.spaces = ft_chrjoin(vars.spaces, ' ');
		vars.i++;
	}
	if (data->left == true)
		vars.str = smart_join(vars.str, vars.spaces);
	else
		vars.str = smart_join(vars.spaces, vars.str);
	if (vars.str != NULL)
		vars.ptr_trigger = 1;
	return (vars);
}

void	p_ptr_mwidth(const char *format, t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = ft_atoi(format + data->i_mwidth.i);
	vars.ulnumber = va_arg(args, unsigned long);
	vars.ptr = ft_strdup("0x");
	if (vars.ulnumber == 0)
		vars.str = ft_strdup("0");
	else
		vars.str = ft_hexgen_long(vars.ulnumber);
	if (vars.str == NULL || vars.ptr == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str) + 2;
	if (vars.str_width < vars.min_width)
		vars = ptr_mwidth(data, vars);
	else
		vars.str = smart_join(vars.ptr, vars.str);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data->result = print_and_free(vars.str, data->result, data->fd);
	return ;
}
