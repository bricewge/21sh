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

#include "21sh.h"
#include "lexer.h"


int	main(int argc, char** argv)
{
	if (argc != 2)
		return 1;

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


int lex_scan_one(char c)
{
	if (c == '\n')
		return (DELIMIT_TKN);
	else
		return NOT_APPLY;
}

int lex_scan_rules(char c)
{
	int		i;

	i = -1;
	while (++i <= 9)
	{
		ret = &rules[i];
		if (ret != NOT_APPLY)
			return ret;
	}
}

int	lex_scan(char *line)
{
	char	token_start;
	int		quoted;
	int		commented;

	quoted = 0;
	commented = 0;
	while (*line)
	{
		lex_scan_rules(*line);
		++line;
	}
}

