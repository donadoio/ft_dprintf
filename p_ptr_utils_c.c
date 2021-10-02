/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_ptr_utils_c.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 15:48:39 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/07 00:40:14 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	p_ptr_dot(t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = 0;
	vars.ulnumber = va_arg(args, unsigned long);
	vars.ptr = ft_strdup("0x");
	if (vars.ulnumber == 0)
		vars.str = vars.ptr;
	else
		vars.str = ft_hexgen_long(vars.ulnumber);
	if (vars.str == NULL || vars.ptr == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str) + 2;
	if (vars.ulnumber != 0)
		vars = ptr_mwidth(data, vars);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data->result = print_and_free(vars.str, data->result, data->fd);
	return ;
}

void	p_ptr_dot_num(const char *format, t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.precision = ft_atoi(format + data->i_dot_num.i);
	vars.ulnumber = va_arg(args, unsigned long);
	vars.ptr = ft_strdup("0x");
	if (vars.ulnumber == 0)
		vars.str = ft_strdup("");
	else
		vars.str = ft_hexgen_long(vars.ulnumber);
	if (vars.str == NULL || vars.ptr == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.str_width < vars.precision)
		vars = ptr_dot_num(vars);
	else
		vars.str = smart_join(vars.ptr, vars.str);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data->result = print_and_free(vars.str, data->result, data->fd);
	return ;
}

void	p_ptr_dot_star(t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = ptr_ds_vars(vars, args);
	if (vars.str == NULL || vars.ptr == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.str_width < vars.precision)
		vars = ptr_dot_num(vars);
	else
		vars.str = smart_join(vars.ptr, vars.str);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data->result = print_and_free(vars.str, data->result, data->fd);
	return ;
}

t_vars	ptr_ndn_vars(char *str, t_vars vars, t_data *data, va_list args)
{
	vars = vars_init(vars);
	vars.min_width = ft_atoi(str + data->i_num_dot_num.i);
	vars.precision = ft_atoi(str + data->i_num_dot_num.j);
	vars.ulnumber = va_arg(args, unsigned long);
	vars.ptr = ft_strdup("0x");
	if (vars.ulnumber == 0)
		vars.str = ft_strdup("");
	else
		vars.str = ft_hexgen_long(vars.ulnumber);
	return (vars);
}
