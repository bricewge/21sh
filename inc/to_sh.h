/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/12/06 18:06:53 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TO_SH_H
# define TO_SH_H
# include "libft.h"

typedef struct		s_cmd
{
	char			*cmd;
	char			**args;
	int				in;
	int				out;
	int				err;
}					t_cmd;

typedef struct		s_parse
{
	t_list			*tkns;
	t_tkn			*cur;
	t_tkn			*prev;
}					t_parse;

// TODO Add to libft
int					ft_isblank(int c);
void				ft_rmsubstr(char *str, const char *substr);
#endif

