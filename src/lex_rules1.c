/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_rules1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 20:08:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "lexer.h"

int lex_rule_one(char *c, t_lex *status)
{
	if (*c == '\0')
	{
		if (status->tknbeg)
			status->delimited = 1;
		return (-1);
	}
	return (0);
}

int lex_rule_two(char *c, t_lex *status)
{
	t_item	*operator;

	if (status->tknbeg)
	{
		operator = char_form_op(c, *status);
		if (tkn_is_op(*status) &&
			status->quoted == 0 &&
			operator)
		{
			status->tkntype = operator->ind;
			(status->tknend)++;
			return (1);
		}
	}
	return (0);
}

int lex_rule_three(char *c, t_lex *status)
{
	t_item	*operator;

	if (status->tknbeg)
	{
		operator = char_form_op(c, *status);
		if (tkn_is_op(*status) &&
			!operator)
		{
			status->delimited = 1;
			return (1);
		}
	}
	return (0);
}

int lex_rule_four(char *c, t_lex *status)
{
	/* TODO Write rule */
	if ((*c == '\\' || *c == '\'' || *c == '"') &&
		status->quoted == 0)
	{
		status->quoted = 1;
		status->tknbeg = c;
		status->tknend = c + 1;
		/* Not sure this is right */
		status->tkntype = WORD;
		return (1);
	}
	else if (status->quoted &&
			 (*(status->tknbeg) == '\\' ||
			  (*(status->tknbeg) == '\'' && *c == '\'') ||
			  (*(status->tknbeg) == '\"' &&  *c == '\"' && *(c - 1) != '\\')
				 ))
	{
		(status->tknend)++;
		status->quoted = 0;
		return (1);
	}
	return (0);
}

int lex_rule_five(char *c, t_lex *status)
{
	/* TODO Write rule */
	return (0);
}
