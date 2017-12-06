/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:44:13 by bwaegene          #+#    #+#             */
/*   Updated: 2017/12/06 18:06:51 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "to_sh.h"

int		parser_ionum(t_parse *status)
{
	int	i;

	if (status->cur->type == WORD)
	{
		i = -1;
		while (status->cur->val[++i])
			if (!ft_isdigit(status->cur->val[i]))
				return (NEXT);
		if (status->tkns->next)
			if (!( *(status->tkns->next->content->val) == '<'
				  || *(status->tkns->next->content->val) == '>'))
				return (NEXT);
		cur->type = IO_NUMBER;
		return (APPLY);
	}
	return (NEXT);
}

int 	parser_cmd(t_tkn *cur, t_tkn *prev)
{
	if (tkn->type == WORD)
	{
		if (!prev)
			tkn->type = CMD_NAME;
		else
			tkn->type = CMD_WORD;
		return (APPLY);
	}
	return (NEXT);
}
