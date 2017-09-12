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
#include "to_sh.h"

int lex_rule_six(char *c, t_lex *status)
{
	/* TODO Write rule */
	if (status->quoted != 0)
		
	return (0);
}

int lex_rule_seven(char *c, t_lex *status)
{
	if (ft_isblank(*c) && status->quoted == 0)
	{
		status->delimited = 1;
		return (1);
	}
	return (0);
}

int lex_rule_eight(char *c, t_lex *status)
{
	if (status->tkntype == WORD)
	{
		(status->tknend)++;
		return (1);
	}
	return (0);
}

int lex_rule_nine(char *c, t_lex *status)
{
	if (*c == '#')
	{
		status->commented = 1;
		return (1);
	}
	return (0);
}

int lex_rule_ten(char *c, t_lex *status)
{
	status->tkntype = WORD;
	status->tknbeg = c;
	status->tknend = c + 1;
	return (1);
}
