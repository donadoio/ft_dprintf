/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_int_utils_d.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 15:37:19 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/06 22:56:40 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static t_vars	int_dn_vars(char *str, t_vars vars, t_data *data, va_list args)
{
	vars = vars_init(vars);
	vars.precision = ft_atoi(str + data->i_dot_num.i);
	vars.number = va_arg(args, int);
	vars = is_int_negative(vars);
	vars.str = ft_itoa(vars.number);
	vars.str = seek_last_number(vars);
	return (vars);
}

void	p_int_dot_num(const char *format, t_data *data, va_list args)
{
	t_vars	vars;

	data->format_detected = true;
	vars.i = 0;
	vars = int_dn_vars((char *)format, vars, data, args);
	if (vars.str == NULL)
		return (print_fail(data, vars));
	vars.str_width = ft_strlen(vars.str);
	if (vars.number == 0 && vars.precision == 0)
		vars.str[0] = '\0';
	else if (vars.str_width < vars.precision)
	{
		vars.spaces = ft_strdup("");
		if (vars.spaces == NULL)
			return (print_fail(data, vars));
		vars = int_dot_num(vars);
		if (vars.str == NULL)
			return (print_fail(data, vars));
	}
	else if (vars.is_negative == true)
		vars.str = ft_chrrjoin('-', vars.str);
	data->result = print_str(vars.str, data->fd);
	free(vars.str);
	return ;
}

t_vars	int_star_vars(t_vars vars, va_list args)
{
	vars.number = va_arg(args, int);
	vars = is_int_negative(vars);
	vars.str = ft_itoa(vars.number);
	vars.str = seek_last_number(vars);
	return (vars);
}

t_vars	int_ds_vars(t_vars vars, va_list args)
{
	vars = vars_init(vars);
	vars.precision = va_arg(args, int);
	vars.number = va_arg(args, int);
	vars = is_int_negative(vars);
	vars.str = ft_itoa(vars.number);
	vars.str = seek_last_number(vars);
	return (vars);
}

char	*seek_last_number(t_vars vars)
{
	size_t	char_count;

	if (vars.str == NULL)
		return (NULL);
	if (vars.negative_max == true)
	{
		char_count = 0;
		while (vars.str[char_count] != '\0')
			char_count++;
		char_count--;
		vars.str[char_count] = '8';
	}
	return (vars.str);
}
