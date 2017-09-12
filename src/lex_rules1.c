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
	/* TODO Write rule */
	return (0);
}

int lex_rule_three(char *c, t_lex *status)
{
	/* TODO Write rule */
	return (0);
}

int lex_rule_four(char *c, t_lex *status)
{
	/* TODO Write rule */
	return (0);
}
int lex_rule_five(char *c, t_lex *status)
{
	/* TODO Write rule */
	return (0);
}
