/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: idonado <idonado@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/22 18:47:05 by idonado       #+#    #+#                 */
/*   Updated: 2020/06/22 18:47:07 by idonado       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static	int	ft_blanks(const char *num)
{
	int	i;

	i = 0;
	while (num[i] == ' ' || num[i] == '\t' || num[i] == '\r' || num[i] \
	== '\v' || num[i] == '\f' || num[i] == '\n' || num[i] == '\b')
		i++;
	return (i);
}

static	int	ft_atoi_signcheck(char sign)
{
	int	sign_num;

	sign_num = 1;
	if (sign == '-')
		return (-1);
	return (sign_num);
}

static int	check_two(int sign)
{
	if (sign == -1)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *num)
{
	int		i;
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	i = ft_blanks(num);
	if (num[i] == '-' || num[i] == '+')
	{
		sign = ft_atoi_signcheck(num[i]);
		i++;
	}
	while (num[i] >= '0' && num[i] <= '9')
	{
		if (result >= 922337203685477580)
		{
			if ((sign == -1 && num[i] >= '9') || (sign == 1 && num[i] >= '8'))
				return (check_two(sign));
			result = (result * 10) + (num[i] - '0');
			return ((int)result * sign);
		}
		result = (result * 10) + (num[i] - '0');
		i++;
	}
	return ((int)result * sign);
}
