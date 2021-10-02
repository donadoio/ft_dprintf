/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_str_utils_a.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 20:59:04 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/07 00:43:15 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

t_vars	str_double_precision(t_data *data, t_vars vars)
{
	if (vars.negative_prec == false)
		vars.str[vars.precision] = '\0';
	if ((int)ft_strlen(vars.str) < vars.min_width)
	{
		vars.min_width = vars.min_width - (int)ft_strlen(vars.str);
		vars.spaces = ft_strdup("");
		while (vars.i < vars.min_width)
		{
			vars.spaces = ft_chrjoin(vars.spaces, ' ');
			vars.i++;
		}
		if (data->left == true)
			vars.str = smart_join(vars.str, vars.spaces);
		else
			vars.str = smart_join(vars.spaces, vars.str);
	}
	return (vars);
}

t_vars	str_double_mwidth(t_data *data, t_vars vars)
{
	vars.min_width = vars.min_width - (int)ft_strlen(vars.str);
	vars.i = 0;
	vars.spaces = ft_strdup("");
	while (vars.i < vars.min_width)
	{
		vars.spaces = ft_chrjoin(vars.spaces, ' ');
		vars.i++;
	}
	if (data->left == true)
		vars.str = smart_join(vars.str, vars.spaces);
	else
		vars.str = smart_join(vars.spaces, vars.str);
	return (vars);
}

void	str_mwidth(t_vars vars, t_data *data)
{
	vars.str_width = vars.min_width - vars.str_width;
	vars.spaces = ft_strdup("");
	while (vars.i < vars.str_width)
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
