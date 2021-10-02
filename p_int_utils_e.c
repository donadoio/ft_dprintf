/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_int_utils_e.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/03 18:55:11 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/07 00:16:32 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

t_vars	check_precision(t_vars vars)
{
	if (vars.precision < 0)
	{
		vars.precision = 1;
		vars.negative_prec = true;
	}
	return (vars);
}

t_vars	int_sds_vars(t_vars vars, t_data *data, va_list args)
{
	vars.precision = va_arg(args, int);
	vars = check_precision(vars);
	vars.number = va_arg(args, int);
	vars = is_int_negative(vars);
	if (data->zeroes == true)
		vars.have_zero = true;
	vars = int_num_dot_num_a(vars);
	return (vars);
}

t_vars	int_sdn_vars(const char *format, t_vars vars, \
t_data *data, va_list args)
{
	vars.precision = ft_atoi(format + data->i_star_dot_num.i);
	vars.number = va_arg(args, int);
	vars = is_int_negative(vars);
	vars = int_num_dot_num_a(vars);
	return (vars);
}

t_vars	int_sd_vars(t_vars vars, va_list args)
{
	vars.number = va_arg(args, int);
	vars.str = ft_itoa(vars.number);
	if (vars.number == 0)
		vars.str[0] = '\0';
	return (vars);
}

t_vars	int_ndn_a_vars(t_vars vars)
{
	if (vars.number == 0)
		vars.str = ft_strdup("");
	else
		vars.str = ft_itoa(vars.number);
	if (vars.str == NULL)
	{
		vars.print_fail = true;
		return (vars);
	}
	return (vars);
}
