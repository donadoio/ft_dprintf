/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_int_utils_b.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 15:51:07 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/07 14:02:59 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	p_int_num_dot_num(const char *format, t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = ft_atoi(format + data->i_num_dot_num.i);
	vars.precision = ft_atoi(format + data->i_num_dot_num.j);
	vars.number = va_arg(args, int);
	vars = is_int_negative(vars);
	vars = int_num_dot_num_a(vars);
	if (vars.print_fail == true)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	vars.i = 0;
	if (vars.str_width < vars.min_width)
	{
		vars.spaces = ft_strdup("");
		if (vars.spaces == NULL)
			return (print_fail(data, vars));
		vars = int_num_dot_num_c(data, vars);
		if (vars.str == NULL)
			return (print_fail(data, vars));
	}
	data->result = print_and_free(vars.str, data->result, data->fd);
	return ;
}

void	p_int_num_dot_star(const char *format, t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = ft_atoi(format + data->i_num_dot_star.i);
	vars = int_nds_vars(vars, data, args);
	if (vars.print_fail == true)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	vars.i = 0;
	if (vars.str_width < vars.min_width)
	{
		vars.spaces = ft_strdup("");
		if (vars.spaces == NULL)
			return (print_fail(data, vars));
		vars = int_num_dot_num_c(data, vars);
		if (vars.str == NULL)
			return (print_fail(data, vars));
	}
	data->result = print_and_free(vars.str, data->result, data->fd);
	return ;
}

void	p_int_star_dot_num(const char *format, t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	switch_negative(&vars.min_width, data);
	vars = int_sdn_vars(format, vars, data, args);
	if (vars.print_fail == true)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	vars.i = 0;
	if (vars.str_width < vars.min_width)
	{
		vars.spaces = ft_strdup("");
		if (vars.spaces == NULL)
			return (print_fail(data, vars));
		vars = int_num_dot_num_c(data, vars);
		if (vars.str == NULL)
			return (print_fail(data, vars));
	}
	data->result = print_and_free(vars.str, data->result, data->fd);
	return ;
}

void	p_int_star_dot_star(t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	switch_negative(&vars.min_width, data);
	vars = int_sds_vars(vars, data, args);
	if (vars.print_fail == true)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	vars.i = 0;
	if (vars.str_width < vars.min_width)
	{
		vars.spaces = ft_strdup("");
		if (vars.spaces == NULL)
			return (print_fail(data, vars));
		vars = int_num_dot_num_c(data, vars);
		if (vars.str == NULL)
			return (print_fail(data, vars));
	}
	data->result = print_and_free(vars.str, data->result, data->fd);
	return ;
}
