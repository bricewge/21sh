/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 20:08:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_isblank(int c)
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}

/* Use ft_strsub(str, 0, 1) instead */
/* char* ft_chartostr(char c) */
/* { */
/* 	char *str; */

/* 	str = (char*)malloc(sizeof(*str) * 2); */
/* 	str[0] = c; */
/* 	str[1] = '\0'; */
/* 	return (str); */
/* } */
