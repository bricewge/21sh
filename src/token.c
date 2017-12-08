/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:50:29 by bwaegene          #+#    #+#             */
/*   Updated: 2017/12/08 10:45:34 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

#include <stdio.h>

t_tkn	*tkn_alloc(char *val, int len, int type)
{
	t_tkn	*tkn;

	tkn = (t_tkn*)malloc(sizeof(*tkn));
	if (tkn)
	{
		tkn->val = ft_strdup(val);
		tkn->len = len;
		tkn->type = type;
	}
	return (tkn);
}

void tkn_print(t_list *elem)
{
	t_tkn	*tkn;

	tkn = (t_tkn*)(elem->content);
	printf("TYPE: %-10s\tVALUE: \033[4m%s\033[0m \n", ops_used()[tkn->type].str, tkn->val);
}


/* void	tknlst_append(t_tkn *tkn, t_lex *status) */
/* { */
/* 	status->tkn_lst->next = */
/* } */
