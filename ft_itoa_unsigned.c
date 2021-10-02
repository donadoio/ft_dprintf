/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_unsigned.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 18:48:34 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/07 14:34:12 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	ft_itoa_spaces(unsigned int n)
{
	unsigned int	spaces;

	spaces = 0;
	while (n > 0)
	{
		n = n / 10;
		spaces++;
	}
	return (spaces);
}

static char	ft_itoa_op(unsigned int *n)
{
	char	c;

	c = (*n % 10) + '0';
	*n = *n / 10;
	return (c);
}

static char	*ft_itoa_process(unsigned int n, unsigned int spaces)
{
	char			*result;
	unsigned int	space_t;

	result = (char *)malloc(sizeof(char) * (spaces + 1));
	if (result == NULL)
		return (NULL);
	space_t = spaces - 1;
	if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		result[space_t] = ft_itoa_op(&n);
		space_t--;
	}
	result[spaces] = '\0';
	return (result);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	unsigned int	spaces;
	unsigned int	temp;
	char			*result;

	if (n == 0 || n == -0)
		return (ft_strdup("0"));
	spaces = 0;
	temp = n;
	spaces = spaces + ft_itoa_spaces(temp);
	result = ft_itoa_process(temp, spaces);
	return (result);
}
