/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_str_utils_c.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 16:27:29 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/06 22:55:49 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	p_str_num_dot(const char *format, t_data *data, va_list args)
{
	t_vars	vars;

	vars.i = 0;
	vars = vars_init(vars);
	data->format_detected = true;
	vars.min_width = ft_atoi(format + data->i_num_dot.i);
	vars.spaces = ft_strdup("");
	while (vars.i < vars.min_width)
	{
		vars.spaces = ft_chrjoin(vars.spaces, ' ');
		vars.i++;
	}
	vars.str = ft_strdup(va_arg(args, char *));
	if (vars.str == NULL)
		vars.str = ft_strdup("(null)");
	if (vars.str == NULL)
	{
		data->result = -1;
		return ;
	}
	free(vars.str);
	data->result = print_str(vars.spaces, data->fd);
	free(vars.spaces);
	return ;
}

void	p_str_dot_num(const char *format, t_data *data, va_list args)
{
	int		max_size;
	char	*str;

	data->format_detected = true;
	max_size = ft_atoi(format + data->i_dot_num.i);
	str = ft_strdup(va_arg(args, char *));
	if (str == NULL)
		str = ft_strdup("(null)");
	if (str == NULL)
	{
		data->result = -1;
		return ;
	}
	if (max_size < (int)ft_strlen(str))
	{
		str[max_size] = 0;
		data->result = print_str(str, data->fd);
	}
	else
		data->result = print_str(str, data->fd);
	free(str);
	return ;
}

void	p_str_dot(t_data *data, va_list args)
{
	int		max_size;
	char	*str;

	data->format_detected = true;
	max_size = 0;
	str = ft_strdup(va_arg(args, char *));
	if (str == NULL)
		str = ft_strdup("(null)");
	if (str == NULL)
	{
		data->result = -1;
		return ;
	}
	if (max_size < (int)ft_strlen(str))
	{
		str[max_size] = 0;
		data->result = print_str(str, data->fd);
	}
	else
		data->result = print_str(str, data->fd);
	free(str);
	return ;
}
