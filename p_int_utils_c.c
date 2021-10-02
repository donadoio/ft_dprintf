/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_int_utils_c.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 15:35:15 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/07 00:53:13 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

t_vars	int_num_dot_num_a(t_vars vars)
{
	vars = int_ndn_a_vars(vars);
	vars.str_width = ft_strlen(vars.str);
	if ((vars.str_width < vars.min_width && vars.str_width > vars.precision \
	&& vars.have_zero == true && vars.is_negative == true && \
	vars.negative_prec == true) || (vars.str_width < vars.min_width && \
	vars.is_negative == true && vars.have_zero && vars.negative_prec == true))
		vars.int_exception = true;
	if (vars.str_width < vars.precision)
	{
		vars.zeroes = ft_strdup("");
		if (vars.zeroes == NULL)
			vars.print_fail = true;
		vars = int_num_dot_num_b(vars);
		if (vars.str == NULL)
			vars.print_fail = true;
	}
	else if (vars.is_negative == true && vars.int_exception == false)
		vars.str = ft_chrrjoin('-', vars.str);
	vars.str = seek_last_number(vars);
	return (vars);
}

t_vars	is_int_negative(t_vars vars)
{
	if (vars.number < 0 && vars.number > -2147483648)
	{
		vars.number = vars.number * -1;
		vars.is_negative = true;
	}
	else if (vars.number < 0 && vars.number == -2147483648)
	{
		vars.number = 2147483647;
		vars.is_negative = true;
		vars.negative_max = true;
	}
	return (vars);
}

void	p_int_mwidth(const char *format, t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = int_mw_vars(format, data, vars, args);
	if (vars.min_width > vars.str_width)
	{
		vars.spaces = ft_strdup("");
		if (vars.spaces == NULL)
			return (print_fail(data, vars));
		vars = int_mwidth(data, vars);
		if (vars.str == NULL)
			return (print_fail(data, vars));
	}
	else if (vars.is_negative == true)
		vars.str = ft_chrrjoin('-', vars.str);
	data->result = print_and_free(vars.str, data->result, data->fd);
	return ;
}

void	p_int_star(t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	switch_negative(&vars.min_width, data);
	vars = int_star_vars(vars, args);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	p_int_util_b(&vars);
	if (vars.str_width < vars.min_width)
	{
		vars.spaces = ft_strdup("");
		if (vars.spaces == NULL)
			return (print_fail(data, vars));
		vars = int_mwidth(data, vars);
		if (vars.str == NULL)
			return (print_fail(data, vars));
	}
	else if (vars.is_negative == true)
		vars.str = ft_chrrjoin('-', vars.str);
	data->result = print_and_free(vars.str, data->result, data->fd);
	return ;
}

void	p_int_dot_star(t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = int_ds_vars(vars, args);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.number == 0 && vars.precision == 0)
		vars.str[0] = '\0';
	else if (vars.str_width < vars.precision)
	{
		vars.spaces = ft_strdup("");
		if (vars.spaces == NULL)
			return (print_fail(data, vars));
		vars = int_dot_num(vars);
		if (vars.str == NULL)
			return (print_fail(data, vars));
	}
	else if (vars.is_negative == true)
		vars.str = ft_chrrjoin('-', vars.str);
	data->result = print_and_free(vars.str, data->result, data->fd);
	return ;
}
