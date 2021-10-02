/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 18:48:50 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/06 21:21:51 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	int		i;
	char	*tmp;

	if (s1 == NULL)
		return (NULL);
	size = 0;
	i = 0;
	size = ft_strlen(s1);
	tmp = malloc(sizeof(char) * size + 1);
	if (tmp == NULL)
		return (NULL);
	while (i < size)
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
