/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:28:51 by armhakob          #+#    #+#             */
/*   Updated: 2023/07/15 14:38:14 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_atoi(char *str)
{
	int result = 0;
	int sign = 1;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
        	str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

int	check_args (char **s)
{
	int	i;
	int	j;
	
	i = 1;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			while (s[i][j] == ' ')
				j++;
			while (s[i][j] == '+')
				j++;
			if ((s[i][j] < '0' || s[i][j] > '9'))
			{
				write(2, "Error\n", 6);
				return (1);
			}
			j++;
		}
		if (ft_atoi(s[i]) == 2147483647)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}	
	return (0);
}

int args_count(char **s)
{
	int	i;
	
	i = 0;
	while (s[i])
		i++;
	if (i > 6)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
int check_sign(char **s)
{
	int	i;
	int	j;

	i = -1;
	while (s && s[++i])
	{
		j = -1;
		while (s[i][++j])
		{
			if (s[i][j] == '+')
				j++;
			if(s[i][j] == '+' && j != 0)
			{
				write(2, "Error\n", 6);
				return (1);
			}
			if (s[i][j] == '-')
			{
				write(2, "Error\n", 6);
				return (1);
			}
		}
	}
	return (0);
}

char	**splited(int argc, char **argv)
{
	int		k;
	char	*join;
	char	**s;


	k = 1;
	s = NULL;
	while (k < argc)
	{
		join = ft_strjoin(join, argv[k]);
		join = ft_strjoin(join, " ");
		k++;
	}
	s = ft_split(join);

	return (s);
}

