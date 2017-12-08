/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/12/07 09:47:48 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_isblank(int c)
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}

int		ft_isnumber(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]))
			return (0);
	return (1);
}

void	ft_rmsubstr(char *str, const char *substr)
{
	int		sublen;

	if (!str || !substr)
		return ;
	sublen = ft_strlen(substr);
	while ((str = ft_strstr(str, substr)))
		ft_memmove(str, str + sublen, 1 + ft_strlen(str + sublen));
}
