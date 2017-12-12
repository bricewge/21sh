/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/12/10 14:38:30 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TO_SH_H
# define TO_SH_H
# include "libft.h"


// TODO Add to libft
int					ft_isblank(int c);
int					ft_isnumber(char *s);
void				ft_rmsubstr(char *str, const char *substr);
#endif

