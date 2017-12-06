/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_rules1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/12/06 09:36:08 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "lexer.h"

int lex_rule_one(char **c, t_lex *status)
{
	if (**c == '\0')
	{
		if (status->curtkn_start)
			lex_delimit_tkn(status);
		return (APPLY);
	}
	return (NEXT);
}

int lex_rule_two(char **c, t_lex *status)
{
	(void)c;
	if (status->curtkn_type == S_OPERATOR && can_form_op(*status))
	{
		(status->curtkn_len)++;
		return (APPLY);
	}
	return (NEXT);
}

int lex_rule_three(char **c, t_lex *status)
{
	(void)c;
	if (status->curtkn_type == S_OPERATOR && !can_form_op(*status))
	{
		lex_delimit_tkn(status);
		--(*c);
		return (APPLY);
	}
	return (NEXT);
}

int lex_rule_four(char **c, t_lex *status)
{
	char quote;

	if (**c == '\'' || **c == '"')
	{
		if (!status->curtkn_start)
		{
			status->curtkn_start = *c;
			status->curtkn_type = WORD;
		}
		quote = **c;
		++(status->curtkn_len);
		while (**c)
		{
			++(*c);
			++(status->curtkn_len);
			if (**c == quote)
				break;
		}
		/* TODO Quoted on several lines */
		return (APPLY);
	}
	return (NEXT);
}

int lex_rule_five(char **c, t_lex *status)
{
	(void)c;
	(void)status;
	return (NEXT);
}
