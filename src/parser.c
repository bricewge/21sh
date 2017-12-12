/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:44:13 by bwaegene          #+#    #+#             */
/*   Updated: 2017/12/11 16:38:03 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "to_sh.h"

#include <stdio.h>

int		parser_ionum(t_parse *status)
{
	t_tkn	*next;

	if (status->cur->type == WORD)
	{
		if (!ft_isnumber(status->cur->val))
			return (NEXT);
		if (status->tkns->next)
			if (status->tkns->next)
			{
				next = (t_tkn*)status->tkns->next->content;
				if (!( *(next->val) == '<'
					   || *(next->val) == '>'))
					return (NEXT);
			}
		status->cur->type = IONUMBER;
		return (APPLY);
	}
	return (NEXT);
}

/*  RULE 7 a/b
**  Usleless unless the folowing type of command is suported: FOO=bar cmd */
/* int 	parser_cmd(t_tkn *cur, t_tkn *prev) */
/* { */
/* 	if (tkn->type == WORD) */
/* 	{ */
/* 		if (prev && ft_strchr(tkn->val, '=')) */
/* 			tkn->type = ASSIGNMENT_WORD; */
/* 		return (APPLY); */
/* 	} */
/* 	return (NEXT); */
/* } */

int		parser_pipe(t_parse *status)
{
	if (status->cur->type == OPERATOR && ft_strequ(status->cur->val, "|"))
	{
		if (!status->prev || status->prev->type != WORD)
			return (ERROR);
		if (!status->next || status->next->type != WORD)
			return (ERROR);
		// TODO Ask for second handside of the pipe
		status->cur->type = PIPE;
		return (APPLY);
	}
	return (NEXT);
}

int		parser_separator(t_parse *status)
{
	if (status->cur->type == OPERATOR && ft_strequ(status->cur->val, ";"))
	{
		if (!status->prev || status->prev->type != WORD)
			return (ERROR);
		status->cur->type = SEPARATOR;
		return (APPLY);
	}
	return (NEXT);
}

int		parser_heredoc(t_parse *status)
{
	if (status->cur->type == OPERATOR && ft_strequ(status->cur->val, "<<"))
	{
		if (status->next && status->next->type != WORD)
			return (ERROR);
		status->cur->type = HEREDOC;
		return (APPLY);
	}
	return (NEXT);
}

int		parser_redirect(t_parse *status)
{
	if (status->cur->type == OPERATOR && isredirop(status->cur->val))
	{
		if (status->next && status->next->type != WORD)
			return (ERROR);
		status->cur->type = REDIRECT;
		return (APPLY);
	}
	return (NEXT);
}

int parser_rules(t_parse *status)
{
	int			i;
	int			ret;
	static int	(*rules[5])(t_parse *status) = {
		parser_ionum, parser_pipe, parser_separator, parser_heredoc, parser_redirect
	};

	i = -1;
	while (++i < 5)
	{
		ret = (rules[i])(status);
		if (ret == APPLY)
			return (i + 1);
		else if (ret == ERROR)
			return (-1);
	}
	return (0);
}

t_list	*parser(t_list *tkns)
{
	t_parse	status;
	int		rule;

	if (!tkns)
		return (NULL);
	status = (t_parse){
		.tkns = tkns, .cur = tkns->content , .prev = NULL, .next = NULL
	};
	while (status.tkns)
	{
		if (status.tkns->next)
			status.next = status.tkns->next->content;
		rule = parser_rules(&status);
		if (rule == -1)
		{
			ft_putendl("/!\\ ERROR /!\\");
			break ;
		}
		/* printf("RULE: %d\n", rule); */
		if (status.tkns)
			status.tkns = status.tkns->next;
		status.prev = status.cur;
		status.cur = status.next;
		/* if (status.cur) */
		/* 	status.next = (t_tkn*)tkns->next->content; */
		/* else */
		/* 	status.next = NULL; */
	}
	return (status.tkns);
}
