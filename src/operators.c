/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/12/08 10:45:16 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "to_sh.h"
#include "lexer.h"
#include "libft.h"

t_item		*ops_long(void)
{
	static t_item	operators[11] = {
		{ANDIF, "&&"}, {DSEMI, ";;"}, {NEWLINE, "\n"},
		{ORIF, "||"}, {CLOBBER, ">|"}, {DLESS, "<<"},
		{DGREAT, ">>"}, {LESSAND, "<&"}, {GREATAND, ">&"},
		{LESSGREAT, "<>"}, {DLESSDASH, "<<-"}
	};

	return (operators);
}

t_item		*ops_used(void)
{
	static t_item	operators[8] = {
		{0, "unknowm"}, {WORD, "word"}, {OPERATOR, "operator"},
		{IONUMBER, "ionum"}, {SEPARATOR, "separator"}, {HEREDOC, "heredoc"},
		{REDIRECT, "redirect"}, {PIPE, "pipe"}
	};

	return (operators);
}

t_item		*ops_single(void)
{
	static t_item	operators[7] = {
		{0, "&"}, {0, "("}, {0, ")"},
		{0, ";"},  {0, "|"}, {0, "<"},
		{0, ">"}
	};

	return (operators);
}

t_item		*operators(void)
{
	static t_item	operators[18] = {
		{0, "&"}, {ANDIF, "&&"}, {0, "("}, {0, ")"}, {0, ";"},
		{DSEMI, ";;"}, {NEWLINE, "\n"}, {0, "|"}, {ORIF, "||"},
		{0, "<"}, {0, ">"}, {CLOBBER, ">|"}, {DLESS, "<<"}, {DGREAT, ">>"},
		{LESSAND, "<&"}, {GREATAND, ">&"}, {LESSGREAT, "<>"}, {DLESSDASH, "<<-"}
	};

	/* printf("--- %d ---\n", operators[1].ind); */
	return (operators);
}


int		compar_item_firstchar(const void *p1, const void *p2)
{
	char			c1;
	char			c2;

	c1 = *((char *)p1);
	c2 = *(((t_item *)p2)->str);
	/* printf("c1: %c\tc2: %c\n", c1, c2); */
	return (c1 == c2 ? 0 : 1);
}

int		compar_item_str(const void *p1, const void *p2)
{
	char			*s1;
	char			*s2;

	s1 = (char *)p1;
	s2 = ((t_item *)p2)->str;
	/* printf("---s1: %s s2: %s---\n", s1, s2); */
	return (ft_strcmp(s1, s2));
}


/* int		tkn_is_op(t_lex status) */
/* { */
/* 	if (status.tkntype == 0 || */
/* 		 (status.tkntype >= ANDIF && status.tkntype <= CLOBBER)) */
/* 		return (1); */
/* 	else */
/* 		return (0); */
/* } */

/*
** If the current char together with the current token can form an operator
** it return this operator or NULL otherwise.
** TODO Only use operators used in 21sh
*/

int		can_form_op(t_lex status)
{
	char	*cur_op;
	int		ret;

	ret = 0;
	cur_op = ft_strsub(status.curtkn_start, 0, status.curtkn_len + 1);
	if (ft_strcmp(cur_op, ">>") == 0 || ft_strcmp(cur_op, "<<") == 0
		|| ft_strcmp(cur_op, ">&") == 0 || ft_strcmp(cur_op, "<&") == 0
		|| ft_strcmp(cur_op, "<>") == 0)
		ret = 1;
	free(cur_op);
	return (ret);
}

int		isredirop(char *s)
{
	int		i;
	char	*redirops[7];

	ft_memcpy(redirops, (char*[]) { "<", "<<", "<&", ">", ">>", ">&", "<>" },
						 sizeof(redirops));
	if (!s)
		return (0);
	i = -1;
	while (++i < 6)
		if (ft_strequ(s, redirops[i]))
			return (1);
	return (0);
}
