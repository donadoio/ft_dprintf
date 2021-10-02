/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_str_utils_b.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 15:30:13 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/07 00:46:19 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	p_str_star_dot(t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	if (vars.min_width < 0)
		vars.min_width = vars.min_width * -1;
	vars.spaces = ft_strdup("");
	vars.i = 0;
	while (vars.i < vars.min_width)
	{
		vars.spaces = ft_chrjoin(vars.spaces, ' ');
		vars.i++;
	}
	vars.str = ft_strdup(va_arg(args, char *));
	if (vars.str == NULL)
		vars.str = ft_strdup("(null)");
	if (vars.str == NULL)
		return (print_fail(data, vars));
	free(vars.str);
	data->result = print_and_free(vars.spaces, data->result, data->fd);
	return ;
}

void	p_str_star_dot_num(const char *format, t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	switch_negative(&vars.min_width, data);
	vars.precision = ft_atoi(format + data->i_star_dot_num.i);
	vars.str = ft_strdup(va_arg(args, char *));
	if (vars.str == NULL)
		vars.str = ft_strdup("(null)");
	if (vars.str == NULL)
		return (print_fail(data, vars));
	if (vars.precision < (int)ft_strlen(vars.str))
		vars = str_double_precision(data, vars);
	if ((int)ft_strlen(vars.str) < vars.min_width)
		vars = str_double_mwidth(data, vars);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data->result = print_and_free(vars.str, data->result, data->fd);
	return ;
}

void	p_str_num_dot_num(const char *format, t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = ft_atoi(format + data->i_num_dot_num.i);
	vars.precision = ft_atoi(format + data->i_num_dot_num.j);
	vars.str = ft_strdup(va_arg(args, char *));
	if (vars.str == NULL)
		vars.str = ft_strdup("(null)");
	if (vars.str == NULL)
		return (print_fail(data, vars));
	if (vars.precision < (int)ft_strlen(vars.str))
		vars = str_double_precision(data, vars);
	if ((int)ft_strlen(vars.str) < vars.min_width)
		vars = str_double_mwidth(data, vars);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data->result = print_and_free(vars.str, data->result, data->fd);
	return ;
}

void	p_str_num_dot_star(const char *format, t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = ft_atoi(format + data->i_num_dot_star.i);
	vars.precision = va_arg(args, int);
	if (vars.precision < 0)
		vars.negative_prec = true;
	vars.str = ft_strdup(va_arg(args, char *));
	if (vars.str == NULL)
		vars.str = ft_strdup("(null)");
	if (vars.str == NULL)
		return (print_fail(data, vars));
	if (vars.precision < (int)ft_strlen(vars.str))
		vars = str_double_precision(data, vars);
	if ((int)ft_strlen(vars.str) < vars.min_width)
		vars = str_double_mwidth(data, vars);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data->result = print_and_free(vars.str, data->result, data->fd);
	return ;
}

void	p_str_star_dot_star(t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	switch_negative(&vars.min_width, data);
	vars.precision = va_arg(args, int);
	if (vars.precision < 0)
		vars.negative_prec = true;
	vars.str = ft_strdup(va_arg(args, char *));
	if (vars.str == NULL)
		vars.str = ft_strdup("(null)");
	if (vars.str == NULL)
		return (print_fail(data, vars));
	if (vars.precision < (int)ft_strlen(vars.str))
		vars = str_double_precision(data, vars);
	if ((int)ft_strlen(vars.str) < vars.min_width)
		vars = str_double_mwidth(data, vars);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data->result = print_and_free(vars.str, data->result, data->fd);
	return ;
}
