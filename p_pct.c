/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_pct.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/21 18:55:01 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/07 00:47:24 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static void	p_pct_mwidth(char *format, t_data *data, va_list args, int star)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = ft_atoi(format + data->i_mwidth.i);
	if (star == 1)
		vars.precision = va_arg(args, int);
	vars.str = ft_strdup("%");
	vars.spaces = ft_strdup("");
	while (vars.i < vars.min_width - 1)
	{
		p_char_util_a(&vars, data);
		vars.i++;
	}
	if (data->left == true)
		vars.str = smart_join(vars.str, vars.spaces);
	else
		vars.str = smart_join(vars.spaces, vars.str);
	data->result = print_and_free(vars.str, data->result, data->fd);
	return ;
}

static void	p_pct_star(t_data *data, va_list args, int star)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	if (star == 1)
		vars.precision = va_arg(args, int);
	switch_negative(&vars.min_width, data);
	vars.str = ft_strdup("%");
	vars.spaces = ft_strdup("");
	while (vars.i < vars.min_width - 1)
	{
		p_char_util_a(&vars, data);
		vars.i++;
	}
	if (data->left == true)
		vars.str = smart_join(vars.str, vars.spaces);
	else
		vars.str = smart_join(vars.spaces, vars.str);
	data->result = print_and_free(vars.str, data->result, data->fd);
	return ;
}

static void	p_pct_ds(va_list args)
{
	va_arg(args, int);
	return ;
}

static void	p_check_pct(const char *format, t_data *data, va_list args)
{
	if (data->mwidth == true)
		p_pct_mwidth((char *)format, data, args, 0);
	else if (data->star == true)
		p_pct_star(data, args, 0);
	else if (data->dot_star == true)
		p_pct_ds(args);
	else if (data->num_dot == true)
	{
		data->i_mwidth.i = data->i_num_dot.i;
		p_pct_mwidth((char *)format, data, args, 0);
	}
	else if (data->num_dot_num == true)
	{
		data->i_mwidth.i = data->i_num_dot_num.i;
		p_pct_mwidth((char *)format, data, args, 0);
	}
	return ;
}

void	p_pct(const char *format, t_data *data, va_list args)
{
	data->format_detected = false;
	p_check_pct(format, data, args);
	if (data->star_dot == true)
		p_pct_star(data, args, 0);
	else if (data->star_dot_num == true)
		p_pct_star(data, args, 0);
	else if (data->num_dot_star == true)
	{
		data->i_mwidth.i = data->i_num_dot_star.i;
		p_pct_mwidth((char *)format, data, args, 1);
	}
	else if (data->star_dot_star == true)
		p_pct_star(data, args, 1);
	else if (data->format_detected == false)
		data->result = print_char('%', data->fd);
	return ;
}
