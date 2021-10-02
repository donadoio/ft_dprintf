/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils_c.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/07 00:35:17 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/07 01:19:48 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	print_and_free(char *str, int result, int fd)
{
	result = print_str(str, fd);
	free(str);
	return (result);
}

void	wipe_struct(t_data *data)
{
	data->left = false;
	data->zeroes = false;
	data->mwidth = false;
	data->dot = false;
	data->dot_num = false;
	data->dot_star = false;
	data->star = false;
	data->star_dot = false;
	data->star_dot_num = false;
	data->star_dot_star = false;
	data->num_dot = false;
	data->num_dot_num = false;
	data->num_dot_star = false;
	data->check_combo = false;
	return ;
}

void	print_data(const char *format, t_data *data, va_list args)
{
	if (data->type_id == 2)
		p_str(format, data, args);
	else if (data->type_id == 1)
		p_char(format, data, args);
	else if (data->type_id == 3)
		p_ptr(format, data, args);
	else if (data->type_id == 4)
		p_int(format, data, args);
	else if (data->type_id == 5)
		p_uint(format, data, args);
	else if (data->type_id == 6)
		p_hex(format, data, args, 0);
	else if (data->type_id == 7)
		p_hex(format, data, args, 1);
	else if (data->type_id == 8)
		p_pct(format, data, args);
	return ;
}
