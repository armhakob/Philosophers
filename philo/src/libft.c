/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:00:51 by armhakob          #+#    #+#             */
/*   Updated: 2023/07/13 11:18:40 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	return (str);
}

char	**ft_split(char *s)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	ret = (char **)malloc(sizeof(char *) * 1000);
	while (*s)
	{
		ret[i] = (char *)malloc(1000);
		while (*s && (*s == ' ' || *s == '\t'))
			s++;
		j = 0;
		while (*s &&  *s != ' ' && *s != '\t')
			ret[i][j++] = *s++;
		ret[i][j] = '\0';
		i++;
	}
	ret[i] = NULL;
	return (ret);
}