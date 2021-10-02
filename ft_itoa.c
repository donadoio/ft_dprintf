/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 18:48:41 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/06 21:21:45 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	ft_itoa_spaces(int n)
{
	int	spaces;

	spaces = 0;
	while (n > 0)
	{
		n = n / 10;
		spaces++;
	}
	return (spaces);
}

static	char	ft_itoa_op(int *n)
{
	char	c;

	c = (*n % 10) + '0';
	*n = *n / 10;
	return (c);
}

static	char	*ft_itoa_process_negative(int n, int spaces)
{
	char	*result;
	int		space_t;

	result = (char *)malloc(sizeof(char) * (spaces + 1));
	if (result == NULL)
		return (NULL);
	result[0] = '-';
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

static	char	*ft_itoa_process_positive(int n, int spaces)
{
	char	*result;
	int		space_t;

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

char	*ft_itoa(int n)
{
	int		spaces;
	int		temp;
	char	*result;

	spaces = 0;
	temp = n;
	if (n == 0 || n == -0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		spaces++;
		temp = n * -1;
		spaces = spaces + ft_itoa_spaces(temp);
		result = ft_itoa_process_negative(temp, spaces);
		return (result);
	}
	else
	{
		spaces = spaces + ft_itoa_spaces(temp);
		result = ft_itoa_process_positive(temp, spaces);
		return (result);
	}
}
