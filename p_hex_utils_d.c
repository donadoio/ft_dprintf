/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_hex_utils_d.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 15:22:27 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/06 22:57:11 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	p_hex_mwidth(const char *format, t_data *data, va_list args, int cap)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = ft_atoi(format + data->i_mwidth.i);
	vars.unumber = va_arg(args, unsigned int);
	if (cap == 0)
		vars.str = ft_hexgen(vars.unumber, 0);
	else
		vars.str = ft_hexgen(vars.unumber, 1);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.str_width < vars.min_width)
		vars = hex_mwidth(data, vars);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data->result = print_str(vars.str, data->fd);
	free(vars.str);
	return ;
}

void	p_hex_star(t_data *data, va_list args, int cap)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	switch_negative(&vars.min_width, data);
	vars.unumber = va_arg(args, unsigned int);
	if (cap == 0)
		vars.str = ft_hexgen(vars.unumber, 0);
	else
		vars.str = ft_hexgen(vars.unumber, 1);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.str_width < vars.min_width)
		vars = hex_mwidth(data, vars);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data->result = print_str(vars.str, data->fd);
	free(vars.str);
	return ;
}

void	p_hex_ds(t_data *data, va_list args, int cap)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.precision = va_arg(args, int);
	if (vars.precision < 0)
		vars.precision = 1;
	vars.unumber = va_arg(args, unsigned int);
	if (vars.unumber == 0)
		vars.str = ft_strdup("");
	else
		vars = hex_capital_check(vars, cap);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.unumber == 0 && vars.precision == 0)
		vars.str[0] = '\0';
	else if (vars.str_width < vars.precision)
		vars = hex_dn(vars);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data->result = print_str(vars.str, data->fd);
	free(vars.str);
	return ;
}

void	p_hex_dn(const char *format, t_data *data, va_list args, int cap)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.precision = ft_atoi(format + data->i_dot_num.i);
	vars.unumber = va_arg(args, unsigned int);
	if (vars.unumber == 0)
		vars.str = ft_strdup("");
	else
		vars = hex_capital_check(vars, cap);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.unumber == 0 && vars.precision == 0)
		vars.str[0] = '\0';
	else if (vars.str_width < vars.precision)
		vars = hex_dn(vars);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data->result = print_str(vars.str, data->fd);
	free(vars.str);
	return ;
}

void	p_hex_nd(const char *format, t_data *data, va_list args, int cap)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = ft_atoi(format + data->i_num_dot.i);
	vars.unumber = va_arg(args, unsigned int);
	if (vars.unumber == 0)
		vars.str = ft_strdup("");
	else
		vars = hex_capital_check(vars, cap);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.str_width < vars.min_width)
		vars = hex_nd(data, vars);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data->result = print_str(vars.str, data->fd);
	free(vars.str);
	return ;
}
