/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_char_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 15:16:32 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/06 22:57:37 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static	void	p_c_mwidth_result(t_vars vars, t_data *data)
{
	if (vars.number == '\0' && data->left == true)
	{
		data->result = print_char('\0', data->fd);
		data->result = data->result + print_str(vars.str, data->fd);
	}
	else if (vars.number == '\0' && data->left == false)
	{
		data->result = print_str(vars.str, data->fd);
		data->result = data->result + print_char('\0', data->fd);
	}
	else
	{
		data->result = print_str(vars.str, data->fd);
	}
	return ;
}

void	p_c_mwidth(const char *format, t_data *data, va_list args)
{
	t_vars	vars;

	vars.i = 0;
	vars = vars_init(vars);
	vars.number = va_arg(args, int);
	vars.min_width = ft_atoi(format + data->i_mwidth.i);
	vars.str = ft_strdup("");
	if (vars.number != '\0')
		vars.str = ft_chrjoin(vars.str, vars.number);
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
	p_c_mwidth_result(vars, data);
	free(vars.str);
	return ;
}

void	p_c_star(t_data *data, va_list args)
{
	t_vars	vars;

	vars.i = 0;
	vars = vars_init(vars);
	vars.min_width = va_arg(args, int);
	if (vars.min_width < 0)
		switch_negative(&vars.min_width, data);
	vars.number = va_arg(args, int);
	vars.str = ft_strdup("");
	if (vars.number != '\0')
		vars.str = ft_chrjoin(vars.str, vars.number);
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
	p_c_mwidth_result(vars, data);
	free(vars.str);
	return ;
}

void	p_c_dot_star(t_data *data, va_list args)
{
	char	c;

	va_arg(args, int);
	c = va_arg(args, int);
	if (c == 0)
		data->result = data->result + 1;
	else
		data->result = print_char(c, data->fd);
	return ;
}

int	p_c_if_none(int result, va_list args, int fd)
{
	char	c;

	c = va_arg(args, int);
	result = print_char(c, fd);
	return (result);
}
