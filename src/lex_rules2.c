/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_rules1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/12/05 10:48:22 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "lexer.h"
#include "to_sh.h"
#include "libft.h"

int lex_rule_six(char **c, t_lex *status)
{
	size_t	nb_ops;
	t_item	*operator;

	nb_ops = 18;
	operator = ft_lfind(*c, (t_arr) {operators(), &nb_ops, sizeof(t_item)},
			 compar_item_firstchar);
	if (operator)
	{
		if (status->curtkn_start)
			lex_delimit_tkn(status);
		status->curtkn_type = S_OPERATOR;
		status->curtkn_start = *c;
		status->curtkn_len = 1;
		return (APPLY);
	}
	return (NEXT);
}

int lex_rule_seven(char **c, t_lex *status)
{
	if (ft_isblank(**c) && status->curtkn_start)
	{
		lex_delimit_tkn(status);
		return (APPLY);
	}
	return (NEXT);
}

int lex_rule_eight(char **c, t_lex *status)
{
	(void)c;
	if (status->curtkn_type == WORD)
	{
		(status->curtkn_len)++;
		return (APPLY);
	}
	return (NEXT);
}

int lex_rule_nine(char **c, t_lex *status)
{
	(void)c;
	(void)status;
	return (NEXT);
}

int lex_rule_ten(char **c, t_lex *status)
{
	status->curtkn_type = WORD;
	status->curtkn_start = *c;
	status->curtkn_len = 1;
	return (APPLY);
}
