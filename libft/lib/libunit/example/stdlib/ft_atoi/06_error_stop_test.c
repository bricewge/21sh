/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_error_stop_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 22:07:09 by starrit           #+#    #+#             */
/*   Updated: 2017/02/11 23:21:57 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		error_stop_test(void)
{
	if (ft_atoi("456ghjk789") == atoi("456ghjk789"))
		return (0);
	else
		return (-1);
}
