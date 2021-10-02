/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 20:31:21 by idonado       #+#    #+#                 */
/*   Updated: 2020/06/22 18:49:45 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static void	check_varied(const char *format, t_data *data)
{
	size_t	j;

	j = data->i;
	if (j == data->i && data->dot == false)
		check_dot(format, data);
	if (j == data->i && data->dot_num == false)
		check_dot_num(format, data);
	if (j == data->i && data->dot_star == false)
		check_dot_star(format, data);
	if (j == data->i && data->star == false)
		check_star(format, data);
	if (j == data->i && data->star_dot == false)
		check_star_dot(format, data);
	if (j == data->i && data->star_dot_num == false)
		check_star_dot_num(format, data);
	if (j == data->i && data->star_dot_star == false)
		check_star_dot_star(format, data);
	if (j == data->i && data->num_dot == false)
		check_num_dot(format, data);
	if (j == data->i && data->num_dot_num == false)
		check_num_dot_num(format, data);
	if (j == data->i && data->num_dot_star == false)
		check_num_dot_star(format, data);
	return ;
}

static void	flag_work_a(const char *format, t_data *data, va_list args)
{
	size_t	i;

	i = data->i;
	if (data->left == false && data->check_combo \
	== false && data->zeroes == false)
		check_left(format, data);
	if (data->zeroes == false && data->check_combo \
	== false && data->left == false)
		check_zeroes(format, data);
	if (data->check_combo == false && data->mwidth == false)
		check_varied(format, data);
	if (data->check_combo == false && data->mwidth == false)
		check_mwidth(format, data);
	data->type_id = type_check(format, data->i);
	if (data->type_id == 0)
	{
		data->result = print_char('%', data->fd);
		data->i = i;
		return ;
	}
	else
		print_data(format, data, args);
	data->i = data->i + 1;
	return ;
}

static void	flag_work(const char *format, va_list args, t_data *data)
{
	wipe_struct(data);
	data->i = data->i + 1;
	flag_work_a(format, data, args);
	return ;
}

static int	printf_workspace(const char *format, va_list args, t_data *data)
{
	int		result;

	data->i = 0;
	result = 0;
	while (format[data->i] != '\0')
	{
		data->result = 0;
		if (format[data->i] == '%')
			flag_work(format, args, data);
		else
		{
			data->result = print_char(format[data->i], data->fd);
			data->i++;
		}
		if (data->result < 0)
			return (-1);
		result = result + data->result;
	}
	return (result);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		result;
	va_list	args;
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (-1);
	data->i = 0;
	data->fd = fd;
	va_start(args, format);
	result = printf_workspace(format, args, data);
	va_end(args);
	free(data);
	return (result);
}
