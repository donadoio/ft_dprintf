/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hexgen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 18:47:30 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/06 21:21:34 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static char	letter_handler_cap(int remainder)
{
	if (remainder == 10)
		return ('A');
	else if (remainder == 11)
		return ('B');
	else if (remainder == 12)
		return ('C');
	else if (remainder == 13)
		return ('D');
	else if (remainder == 14)
		return ('E');
	else if (remainder == 15)
		return ('F');
	return (0);
}

static char	letter_handler(int remainder)
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
	while (str[i + 1] != '\0')
		i++;
	while (i >= 0)
	{
		hex = ft_chrjoin(hex, str[i]);
		i--;
	}
	free(str);
	return (hex);
}

char	*ft_hexgen(unsigned int number, int capital)
{
	unsigned int	copy;
	int				remainder;
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
		{
			if (capital == 0)
				str = ft_chrjoin(str, letter_handler(remainder));
			else
				str = ft_chrjoin(str, letter_handler_cap(remainder));
		}
	}
	if (number == 0)
		str = ft_chrjoin(str, '0');
	else
		str = sort_hex(str);
	return (str);
}
