/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 20:08:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_sh.h"
#include "lexer.h"
#include "libft.h"

#include <stdio.h>

char* ft_chartostr(char c)
{
	char *str;

	str = (char*)malloc(sizeof(*str) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

/*
** http://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_03
** Result of the rules
** - Don't apply
** - Delimit the current token
** - Discard the char
** - Discard upto \n
** - Start a new token
*/

int lex_rules(char *c, t_lex *status)
{
	int			i;
	int			ret;
	static int	(*rules[10])(char *c, t_lex *status) = {
		lex_rule_one,	lex_rule_two,	lex_rule_three,	lex_rule_four,
		lex_rule_five,	lex_rule_six,	lex_rule_seven,	lex_rule_eight,
		lex_rule_nine,	lex_rule_ten
	};

	i = -1;
	while (++i <= 9)
	{
		ret = (rules[i])(c, status);
		if (ret != 0)
		{
			printf("rule #%d retruned %d\n", i + 1, ret);
			return ret;
		}
	}
	return (0);
}

void lex_commented(char **line, t_lex *status)
{
	if (status->commented == 1)
	{
		status->commented = 0;
		while (**line)
		{
			if (**line == '\n' || **line == '\0')
				return;
			++(*line);
		}
	}
}

void lex_delimited(t_lex *status)
{
	if (status->delimited == 1)
	{
	/* TODO add to the linked list of tokens */
		status->delimited = 0;
		status->tkntype = -1;
		status->tknbeg = NULL;
		status->tknend = NULL;
	}
}

void lexer_debug(t_lex status)
{
	char *tmp = NULL;

	if (status.tknbeg)
		tmp = ft_strsub(status.tknbeg, 0, status.tknend - status.tknbeg);
	printf("token: %s\n", tmp);
	free(tmp);
	printf("tkntype: %d\n", status.tkntype);
	printf("delimited: %d\tquoted: %d\tcommented: %d\n\n",
		   status.delimited, status.quoted, status.commented);
}

int	lexer(char *line)
{
	static t_lex	status = {
		.delimited = 0, .quoted = 0, .commented = 0,
		.tknbeg = NULL, .tknend = NULL, .tkntype = -1,
	};

	while (42)
	{
		lex_commented(&line, &status);
		lex_delimited(&status);
		lex_rules(line, &status);
		printf("char: %c (%d)\n", *line, *line);
		lexer_debug(status);
		if (!*line)
			break;
		++line;
	}
	return (1);
}

int	main(int argc, char** argv)
{
	if (argc != 2)
		return 1;
	lexer(argv[1]);
	printf("For=%d, Lbrace=%d", For, Lbrace);
	return (0);
}

int		lex_operators(char c)
{
	static t_item	operators[18] = {
		{0, "&"}, {ANDIF, "&&"}, {0, "("}, {0, ")"}, {0, ";"},
		{DSEMI, ";;"}, {NEWLINE, "\n"}, {0, "|"}, {ORIF, "||"},
		{0, "<"}, {0, ">"}, {CLOBBER, ">|"}, {DLESS, "<<"}, {DGREAT, ">>"},
		{LESSAND, "<&"}, {GREATAND, ">&"}, {LESSGREAT, "<>"}, {DLESSDASH, "<<-"}
	};
	int				i;

	i = -1;
	while (++i < 18)
	{
		if (operators[i].str[0] == c)
			return (operators[i].ind);
	}
	return (-1);
};
