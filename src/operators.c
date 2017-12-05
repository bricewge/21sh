/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/12/05 12:09:45 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "to_sh.h"
#include "lexer.h"
#include "libft.h"

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
	size_t	nb_ops;
	t_item	*operator;
	char	*cur_op;

	nb_ops = 18;
	cur_op = ft_strsub(status.curtkn_start, 0, status.curtkn_len + 1);
	operator = ft_lfind(cur_op,
						(t_arr) {operators(), &nb_ops, sizeof(*operator)},
						compar_item_str);
	free(cur_op);
	return (operator ? 1 : 0);
}
