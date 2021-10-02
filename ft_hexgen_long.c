/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hexgen_long.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 15:21:20 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/06 21:21:42 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static char	letter_handler(unsigned long remainder)
{
	if (remainder == 10)
		return ('a');
	else if (remainder == 11)
		return ('b');
	else if (remainder == 12)
		return ('c');
	else if (remainder == 13)
		return ('d');
	else if (remainder == 14)
		return ('e');
	else if (remainder == 15)
		return ('f');
	return (0);
}

static char	*sort_hex(char *str)
{
	ssize_t	i;
	char	*hex;

	i = 0;
	hex = ft_strdup("");
	if (hex == NULL)
		return (NULL);
	while (str[i + 1] != '\0' && str[i] != '\0')
		i++;
	while (i >= 0)
	{
		hex = ft_chrjoin(hex, str[i]);
		i--;
	}
	free(str);
	return (hex);
}

char	*ft_hexgen_long(unsigned long number)
{
	unsigned long	copy;
	unsigned long	remainder;
	char			*str;

	str = ft_strdup("");
	copy = number;
	while (copy > 0)
	{
		remainder = copy % 16;
		copy = copy / 16;
		if (remainder <= 9)
			str = ft_chrjoin(str, remainder + 48);
		else
			str = ft_chrjoin(str, letter_handler(remainder));
	}
	str = sort_hex(str);
	return (str);
}
