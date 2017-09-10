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


int lex_rule_one(char c, t_lex *status)
{
	if (c == '\0' && status->started == 1)
	{
		status->delimited = 1;
		return (1);
	}
	return (0);
}

int lex_rule_two(char c, t_lex *status)
{
	/* TODO Write rule */
	return (0);
}

int lex_rule_three(char c, t_lex *status)
{
	/* TODO Write rule */
	return (0);
}

int lex_rule_four(char c, t_lex *status)
{
	/* TODO Write rule */
	return (0);
}
int lex_rule_five(char c, t_lex *status)
{
	/* TODO Write rule */
	return (0);
}

int lex_rule_six(char c, t_lex *status)
{
	/* TODO Write rule */
	return (0);
}

int lex_rule_seven(char c, t_lex *status)
{
	if (ft_isblank(c) && status->quoted == 0)
	{
		status->delimited = 1;
		return (1);
	}
	return (0);
}

int lex_rule_eight(char c, t_lex *status)
{
	if (status->token.type == WORD)
	{
		status->token.val = ft_strjoinf(status->token.val, ft_chartostr(c), 3);
			return (1);
	}
	return (0);
}

int lex_rule_nine(char c, t_lex *status)
{
	if (c == '#')
	{
		status->commented = 1;
		return (1);
	}
	/* Not sure the following is the right way to go */
	else if (status->commented == 1 && c == '\n')
	{
		status->token.type = NEWLINE;
		status->token.val = "\0";
		status->delimited = 0;
		status->commented = 0;
		return (1);
	}
	return (0);
}

int lex_rule_ten(char c, t_lex *status)
{
	status->started = 1;
	status->token.type = WORD;
	free(status->token.val);
	status->token.val = (char*)malloc(sizeof(char) * 2);
	status->token.val[0] = c;
	status->token.val[1] = '\0';
	return (1);
}


int lex_rules(char c, t_lex *status)
{
	int			i;
	int			ret;
	static int	(*rules[10])(char c, t_lex *status) = {
		lex_rule_one,	lex_rule_two,	lex_rule_three,	lex_rule_four,
		lex_rule_five,	lex_rule_six,	lex_rule_seven,	lex_rule_eight,
		lex_rule_nine,	lex_rule_ten
	};

	i = -1;
	while (++i <= 9)
	{
		ret = (rules[i])(c, status);
		/* if (ret != NOT_APPLY) */
		if (ret != 0)
		{
			printf("%d\n", i);
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
			if (**line == '\n')
				break;
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
		status->started = 0;
		status->token.val = NULL;
		status->token.type = -1;
	}
}

void lexer_debug(t_lex status)
{
	printf("tkn.val: %s\n", status.token.val);
	printf("tkn.type: %d\n", status.token.type);
	printf("started: %d\tdelimited: %d\tquoted: %d\tcommented: %d\n",
		   status.started, status.delimited, status.quoted, status.commented);
}

int	lexer(char *line)
{
	static t_lex	status = {
		.token.val = NULL, .token.type = -1,
		.started = 0, .delimited = 0, .quoted = 0, .commented = 0
	};

	while (*line)
	{
		lex_commented(&line, &status);
		lex_rules(*line, &status);
		lex_delimited(&status);
		lexer_debug(status);
		++line;
	}
	return (1);
}

int	main(int argc, char** argv)
{
	if (argc != 2)
		return 1;
	lexer(argv[1]);
	return (0);
}

/* int		test_categories(void) */
/* { */
/* 	static t_item operators[17] = { */
/* 		{0, "&"}, */
/* 		{0, "("}, */
/* 		{0, ")"}, */
/* 		{0, ";"}, */
/* 		{0, "\n"}, */
/* 		{0, "|"}, */
/* 		{ANDIF, "&&"}, */
/* 		{ORIF, "||"}, */
/* 		{0, "<"}, */
/* 		{0, ">"}, */
/* 		{DSEMI, ";;"}, */
/* 		{DLESS, "<<"}, */
/* 		{DGREAT, ">>"}, */
/* 		{LESSAND, "<&"}, */
/* 		{GREATAND, ">&"}, */
/* 		{LESSGREAT, "<>"}, */
/* 		{DLESSDASH, "<<-"} */
/* 	}; */
/* }; */
