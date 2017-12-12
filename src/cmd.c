/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:21:15 by bwaegene          #+#    #+#             */
/*   Updated: 2017/12/11 16:38:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

#include <stdio.h>

int		cmd_word(t_parse status, t_list *cmds)
{

	if (cmds->content->)
}


t_list	cmd(t_list *tkns)
{
	t_parse	status;
	t_list	*cmds;
	static int	(cmd_table[7])(t_parse status, t_list *cmds) = {
		cmd_word, cmd_operator, cmd_ionumber, cmd_separator,
		cmd_heredoc, cmd_redirect, cmd_pipe
	};
	int		ret;

	if (!tkns)
		return (NULL);
	status = (t_parse){
		.tkns = tkns, .cur = tkns->content , .prev = NULL, .next = NULL
	};
	ret = 0;
	cmds = ft_lstnew(ft_memalloc(sizeof(ft_cmd)), sizeof(ft_cmd));
	while (tkns.next)
	{
		if (status.tkns->next)
			status.next = status.tkns->next->content;
		ret = cmd_table[tkns->content->type];
		/* printf("") */
		if (status.tkns)
			status.tkns = status.tkns->next;
		status.prev = status.cur;
		status.cur = status.next;
		/* tkns = tkns->next; */
	}
	return (ret);
}
