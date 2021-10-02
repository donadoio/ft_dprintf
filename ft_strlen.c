/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 18:48:58 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/07 14:34:37 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

size_t	ft_strlen(const char *str)
{
	size_t	char_count;

	char_count = 0;
	while (str[char_count] != '\0')
		char_count++;
	return (char_count);
}
