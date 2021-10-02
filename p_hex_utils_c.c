/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_hex_utils_c.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 15:14:45 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/07 00:08:09 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

t_vars	hex_capital_check(t_vars vars, int capital)
{
	if (capital == 0)
		vars.str = ft_hexgen(vars.unumber, 0);
	else
		vars.str = ft_hexgen(vars.unumber, 1);
	return (vars);
}

t_vars	hex_sds_var(t_vars vars, t_bool *left, t_bool zeroes, va_list args)
{
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	if (vars.min_width < 0)
	{
		*left = true;
		vars.min_width = vars.min_width * -1;
	}
	vars.precision = va_arg(args, int);
	vars.unumber = va_arg(args, unsigned int);
	if (vars.unumber == 0)
		vars.str = ft_strdup("");
	else
		vars = hex_capital_check(vars, vars.cap);
	vars = check_precision(vars);
	if (vars.precision == 0 && zeroes == true && \
	(int)ft_strlen(vars.str) < vars.min_width)
		vars.hex_exception = true;
	return (vars);
}

t_vars	hex_sdn_var(const char *format, t_vars vars, va_list args, t_data *data)
{
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	if (vars.min_width < 0)
	{
		vars.min_width = vars.min_width * -1;
		vars.negative_min_width = true;
	}
	vars.precision = ft_atoi(format + data->i_star_dot_num.i);
	vars.unumber = va_arg(args, unsigned int);
	if (vars.precision < 0)
		vars.precision = 1;
	if (vars.unumber == 0)
		vars.str = ft_strdup("");
	else
		vars = hex_capital_check(vars, vars.cap);
	if (vars.precision == 0 && data->zeroes == true && \
	(int)ft_strlen(vars.str) < vars.min_width)
		vars.hex_exception = true;
	return (vars);
}

t_vars	hex_nds_var(const char *format, t_vars vars, va_list args, t_data *data)
{
	vars = vars_init(vars);
	vars.min_width = ft_atoi(format + data->i_num_dot_star.i);
	vars.precision = va_arg(args, int);
	vars.unumber = va_arg(args, unsigned int);
	vars = check_precision(vars);
	if (vars.unumber == 0)
		vars.str = ft_strdup("");
	else
		vars = hex_capital_check(vars, vars.cap);
	if (vars.precision == 0 && data->zeroes == true && \
	(int)ft_strlen(vars.str) < vars.min_width)
		vars.hex_exception = true;
	return (vars);
}

t_vars	hex_ndn_var(const char *format, t_vars vars, va_list args, t_data *data)
{
	vars = vars_init(vars);
	vars.min_width = ft_atoi(format + data->i_num_dot_num.i);
	vars.precision = ft_atoi(format + data->i_num_dot_num.j);
	vars.unumber = va_arg(args, unsigned int);
	if (vars.unumber == 0)
		vars.str = ft_strdup("");
	else
		vars = hex_capital_check(vars, vars.cap);
	if (vars.precision == 0 && data->zeroes == true && \
	(int)ft_strlen(vars.str) < vars.min_width)
		vars.hex_exception = true;
	return (vars);
}
