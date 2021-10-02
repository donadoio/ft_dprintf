/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_int_utils_f.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 00:19:26 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/07 01:07:19 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	p_int_util_a(t_vars *vars, t_data *data)
{
	if (data->zeroes == true && vars->negative_prec == true)
		vars->spaces = ft_chrjoin(vars->spaces, '0');
	else
		vars->spaces = ft_chrjoin(vars->spaces, ' ');
	return ;
}

void	p_int_util_b(t_vars *vars)
{
	if (vars->is_negative == false)
		vars->str_width = ft_strlen(vars->str);
	else
		vars->str_width = ft_strlen(vars->str) + 1;
	return ;
}

t_vars	int_mw_vars(const char *format, t_data *data, t_vars vars, va_list args)
{
	vars = vars_init(vars);
	vars.number = va_arg(args, int);
	vars = is_int_negative(vars);
	vars.str = ft_itoa(vars.number);
	vars.str = seek_last_number(vars);
	vars.min_width = ft_atoi(format + data->i_mwidth.i);
	p_int_util_b(&vars);
	return (vars);
}

t_vars	int_nds_vars(t_vars vars, t_data *data, va_list args)
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
