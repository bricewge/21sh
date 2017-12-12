/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/12/11 16:11:47 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_sh.h"
#include "lexer.h"
#include "libft.h"
#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

void lex_delimit_tkn(t_lex *status)
{
	t_tkn	*tkn;
	char	*val;

	val = ft_strsub(status->curtkn_start, 0, status->curtkn_len);
	tkn = tkn_alloc(val, status->curtkn_len, status->curtkn_type);
	free(val);
	/* tkn_print(*status, *tkn); */
	if (!status->tknlst_start)
	{
		status->tknlst_start = ft_lstnew((const void*)tkn, sizeof(t_tkn));
		status->tknlst_last = status->tknlst_start;
	}
	else
	{
		status->tknlst_last->next = ft_lstnew((const void*)tkn, sizeof(t_tkn));
		status->tknlst_last = status->tknlst_last->next;
	}
	status->curtkn_start = NULL;
	status->curtkn_len = 0;
	status->curtkn_type = -1;
}

int lex_rules(char **c, t_lex *status)
{
	int			i;
	int			ret;
	static int	(*rules[10])(char **c, t_lex *status) = {
		lex_rule_one,	lex_rule_two,	lex_rule_three,	lex_rule_four,
		lex_rule_five,	lex_rule_six,	lex_rule_seven,	lex_rule_eight,
		lex_rule_nine,	lex_rule_ten
	};

	i = -1;
	while (++i <= 9)
	{
		ret = (rules[i])(c, status);
		if (ret == APPLY)
			return (i);
	}
	return (0);
}

t_list	*lexer(char *line)
{
	t_lex	status;
	int		rule;

	status = (t_lex){
		.curtkn_start = line, .curtkn_len = 0, .curtkn_type = -1,
		.tknlst_start = NULL, .tknlst_last = NULL
	};

	while (42)
	{
		rule = lex_rules(&line, &status) + 1;
		/* printf("RULE: %d\n", rule); */
		/* printf("char: %c (%d)\n", *line, *line); */
		if (!*line)
			break;
		++line;
	}
	if (status.curtkn_start)
		lex_delimit_tkn(&status);
	return (status.tknlst_start);
}

int	main(int argc, char** argv)
{
	char	*line;
	int 	i;
	int		fd;
	int		ret;
	t_list	*tkns;
	t_list	*cmds;

	if (argc != 2)
		return 1;
	fd = open(argv[1], O_RDONLY);
	ret = 1;
	i = -1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (line)
		{
			ft_putendl(line);
			tkns = lexer(line);
			/* ft_lstiter(tkns, tkn_print); */
			parser(tkns);
			/* ft_putendl("PARSER"); */
			ft_lstiter(tkns, tkn_print);
			cmds = cmd(tkns);
			/* exec(cmds); */
			ft_putchar('\n');
			free(line);
		}
	}
	close(fd);
	return (0);
}
