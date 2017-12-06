/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 10:50:29 by bwaegene          #+#    #+#             */
/*   Updated: 2017/12/05 17:39:27 by bwaegene         ###   ########.fr       */
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

void tkn_print(t_lex status, t_tkn tkn)
{
	(void)status;
	printf("TYPE: %d\t\tVALUE: \033[4m%s\033[0m \n", tkn.type, tkn.val);
}

/* TODO
void	tkn_insert(t_tkn tkn, t_lex status);
*/
