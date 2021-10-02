/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_int.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 13:42:47 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/07 13:44:49 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static void	p_int_num_dot(const char *format, t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = ft_atoi(format + data->i_num_dot.i);
	vars.number = va_arg(args, int);
	vars.str = ft_itoa(vars.number);
	if (vars.number == 0)
		vars.str[0] = '\0';
	if (vars.str == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.str_width < vars.min_width)
	{
		vars.spaces = ft_strdup("");
		if (vars.spaces == NULL)
			return (print_fail(data, vars));
		vars = int_num_dot(data, vars);
		if (vars.str == NULL)
			return (print_fail(data, vars));
	}
	data->result = print_and_free(vars.str, data->result, data->fd);
	return ;
}

static void	p_int_star_dot(t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	switch_negative(&vars.min_width, data);
	vars = int_sd_vars(vars, args);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.str_width < vars.min_width)
	{
		vars.spaces = ft_strdup("");
		if (vars.spaces == NULL)
			return (print_fail(data, vars));
		vars = int_num_dot(data, vars);
		if (vars.str == NULL)
			return (print_fail(data, vars));
	}
	data->result = print_and_free(vars.str, data->result, data->fd);
	return ;
}

static void	p_int_dot(t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.number = va_arg(args, int);
	if (vars.number == 0)
		vars.str = ft_strdup("");
	else
		vars.str = ft_itoa(vars.number);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	data->result = print_and_free(vars.str, data->result, data->fd);
	return ;
}

static	void	check_int(const char *format, t_data *data, va_list args)
{
	if (data->mwidth == true)
		p_int_mwidth(format, data, args);
	else if (data->star == true)
		p_int_star(data, args);
	else if (data->dot_star == true)
		p_int_dot_star(data, args);
	else if (data->dot_num == true)
		p_int_dot_num(format, data, args);
	else if (data->num_dot == true)
		p_int_num_dot(format, data, args);
	else if (data->star_dot == true)
		p_int_star_dot(data, args);
	else if (data->dot == true)
		p_int_dot(data, args);
	return ;
}

void	p_int(const char *format, t_data *data, va_list args)
{
	char	*str;

	data->format_detected = false;
	check_int(format, data, args);
	if (data->num_dot_num == true)
		p_int_num_dot_num(format, data, args);
	else if (data->num_dot_star == true)
		p_int_num_dot_star(format, data, args);
	else if (data->star_dot_num == true)
		p_int_star_dot_num(format, data, args);
	else if (data->star_dot_star == true)
		p_int_star_dot_star(data, args);
	else if (data->format_detected == false)
	{
		str = ft_itoa(va_arg(args, int));
		data->result = print_and_free(str, data->result, data->fd);
	}
	return ;
}
