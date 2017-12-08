/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/12/08 12:55:46 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TO_SH_H
# define TO_SH_H
# include "libft.h"

typedef struct		s_cmd
{
	char			*cmd;
	char			**args;
	char			**envp;
	int				fd_in;
	int				fd_out;
	int				fd_err;
}					t_cmd;

// TODO Add to libft
int					ft_isblank(int c);
int					ft_isnumber(char *s);
void				ft_rmsubstr(char *str, const char *substr);
#endif

