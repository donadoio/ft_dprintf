/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 18:40:29 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/06 21:21:05 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

char	*ft_chrjoin(char *str, int c)
{
	char	*result;
	size_t	i;

	if (str == NULL)
		return (NULL);
	result = malloc(ft_strlen(str) + 2);
	if (!result)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = c;
	i++;
	result[i] = '\0';
	free(str);
	return (result);
}
