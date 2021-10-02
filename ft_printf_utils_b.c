/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils_b.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 15:12:44 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/05 21:48:36 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

t_vars	vars_init(t_vars vars)
{
	vars.ptr_trigger = 0;
	vars.is_negative = false;
	vars.negative_max = false;
	vars.negative_prec = false;
	vars.negative_min_width = false;
	vars.hex_exception = false;
	vars.int_exception = false;
	vars.have_zero = false;
	vars.str = NULL;
	vars.spaces = NULL;
	vars.zeroes = NULL;
	vars.ptr = NULL;
	vars.print_fail = false;
	return (vars);
}

int	type_check(const char *format, size_t end)
{
	if (format[end] == 'c')
		return (1);
	else if (format[end] == 's')
		return (2);
	else if (format[end] == 'p')
		return (3);
	else if (format[end] == 'd' || format[end] == 'i')
		return (4);
	else if (format[end] == 'u')
		return (5);
	else if (format[end] == 'x')
		return (6);
	else if (format[end] == 'X')
		return (7);
	else if (format[end] == '%')
		return (8);
	return (0);
}

void	switch_negative(int *mwidth, t_data *data)
{
	if (*mwidth < 0)
	{
		*mwidth = *mwidth * -1;
		data->left = true;
		data->zeroes = false;
	}
	return ;
}

void	switch_unegative(int *mwidth, t_data *data)
{
	if (*mwidth < 0)
	{
		*mwidth = *mwidth * -1;
		data->left = true;
	}
	return ;
}

void	print_fail(t_data *data, t_vars vars)
{
	data->result = -1;
	if (vars.spaces != NULL)
		free(vars.spaces);
	if (vars.str != NULL)
		free(vars.str);
	if (vars.zeroes != NULL)
		free(vars.zeroes);
	if (vars.ptr != NULL)
		free(vars.zeroes);
	return ;
}
