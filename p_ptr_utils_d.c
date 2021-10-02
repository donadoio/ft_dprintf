/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_ptr_utils_d.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 16:27:18 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/07 00:38:56 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

t_vars	ptr_nds_vars(char *str, t_vars vars, t_data *data, va_list args)
{
	vars = vars_init(vars);
	vars.min_width = ft_atoi(str + data->i_num_dot_star.i);
	vars.precision = va_arg(args, int);
	vars.ulnumber = va_arg(args, unsigned long);
	vars.ptr = ft_strdup("0x");
	if (vars.ulnumber == 0)
		vars.str = ft_strdup("");
	else
		vars.str = ft_hexgen_long(vars.ulnumber);
	return (vars);
}

t_vars	ptr_sdn_vars(char *str, t_vars vars, t_data *data, va_list args)
{
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	switch_negative(&vars.min_width, data);
	vars.precision = ft_atoi(str + data->i_star_dot_num.i);
	vars.ulnumber = va_arg(args, unsigned long);
	vars.ptr = ft_strdup("0x");
	if (vars.ulnumber == 0)
		vars.str = ft_strdup("");
	else
		vars.str = ft_hexgen_long(vars.ulnumber);
	return (vars);
}

t_vars	ptr_sds_vars(t_vars vars, t_data *data, va_list args)
{
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	switch_negative(&vars.min_width, data);
	vars.precision = va_arg(args, int);
	vars.ulnumber = va_arg(args, unsigned long);
	vars.ptr = ft_strdup("0x");
	if (vars.ulnumber == 0)
		vars.str = ft_strdup("");
	else
		vars.str = ft_hexgen_long(vars.ulnumber);
	return (vars);
}

t_vars	ptr_ds_vars(t_vars vars, va_list args)
{
	vars = vars_init(vars);
	vars.precision = va_arg(args, int);
	if (vars.precision < 0)
		vars.precision = 1;
	vars.ulnumber = va_arg(args, unsigned long);
	vars.ptr = ft_strdup("0x");
	if (vars.ulnumber == 0)
		vars.str = ft_strdup("");
	else
		vars.str = ft_hexgen_long(vars.ulnumber);
	return (vars);
}

void	p_ptr_star_dot(t_data *data, va_list args)
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
