/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils_a.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 15:32:34 by idonado       #+#    #+#                 */
/*   Updated: 2020/07/06 22:57:56 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	print_str(char *s, int fd)
{
	ssize_t	ret;

	if (s == NULL)
		return (-1);
	ret = write(fd, s, ft_strlen(s));
	return ((int)ret);
}

int	print_char(char c, int fd)
{
	ssize_t	ret;

	ret = write(fd, &c, 1);
	return ((int)ret);
}

static char	*free_and_return_null(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (NULL);
}

static void	free_set_null(char *s1, char *s2)
{
	free(s1);
	s1 = NULL;
	free(s2);
	s2 = NULL;
}

char	*smart_join(char *s1, char *s2)
{
	char	*temp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (free_and_return_null(s1, s2));
	temp = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!temp)
		return (free_and_return_null(s1, s2));
	while (s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		temp[i] = s2[j];
		i++;
		j++;
	}
	temp[i] = 0;
	free_set_null(s1, s2);
	return (temp);
}
