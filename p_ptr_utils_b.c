/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_ptr_utils_b.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 15:48:47 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/07 13:48:49 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	p_ptr_star(t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	switch_negative(&vars.min_width, data);
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

void	p_ptr_num_dot(const char *format, t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = ft_atoi(format + data->i_num_dot.i);
	vars.ulnumber = va_arg(args, unsigned long);
	vars.ptr = ft_strdup("0x");
	if (vars.ulnumber == 0)
		vars.str = ft_strdup("");
	else
		vars.str = ft_hexgen_long(vars.ulnumber);
	if (vars.str == NULL || vars.ptr == NULL)
		return (print_fail(data, vars));
	p_ptr_util_a(&vars);
	if (vars.str_width < vars.min_width)
		vars = ptr_mwidth(data, vars);
	else
		vars.str = smart_join(vars.ptr, vars.str);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data->result = print_and_free(vars.str, data->result, data->fd);
	return ;
}

void	p_ptr_ndn(const char *format, t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = ptr_ndn_vars((char *)format, vars, data, args);
	if (vars.str == NULL || vars.ptr == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.str_width < vars.precision)
		vars = ptr_double_precision(vars);
	if (vars.str_width < vars.min_width)
		vars = ptr_double_mwidth(data, vars);
	if (vars.str != NULL && vars.ptr_trigger == 0)
		vars.str = smart_join(vars.ptr, vars.str);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data->result = print_and_free(vars.str, data->result, data->fd);
	return ;
}

t_vars	ptr_mwidth_if(t_vars vars, t_data *data)
{
	if (data->zeroes == true && data->left == false)
	{
		vars.str = smart_join(vars.spaces, vars.str);
		vars.str = smart_join(vars.ptr, vars.str);
	}
	else if (data->left == true)
	{
		vars.str = smart_join(vars.ptr, vars.str);
		vars.str = smart_join(vars.str, vars.spaces);
	}
	else
	{
		vars.str = smart_join(vars.ptr, vars.str);
		vars.str = smart_join(vars.spaces, vars.str);
	}
	return (vars);
}
