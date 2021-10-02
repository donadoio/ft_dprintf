/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrrjoin.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 18:40:38 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/06 21:21:13 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static	char	*ft_chrrjoin_loop(char *result, char *str, size_t i, size_t j)
{
	while (str[j] != '\0')
	{
		result[i] = str[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_chrrjoin(int c, char *str)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	result = malloc(ft_strlen(str) + 2);
	if (!result)
		return (NULL);
	i = 1;
	j = 0;
	result[0] = c;
	result = ft_chrrjoin_loop(result, str, i, j);
	free(str);
	return (result);
}
