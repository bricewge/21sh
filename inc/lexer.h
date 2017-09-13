/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/01/27 20:08:00 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
/* # include "libft.h" */
#include "to_sh.h"

enum				e_words
{
	WORD = 1, ASSIGNMENT_WORD, NAME, NEWLINE, IO_NUMBER,
};

enum				e_operators
{
	ANDIF = IO_NUMBER +1, ORIF, DSEMI,
	DLESS, DGREAT, LESSAND, GREATAND, LESSGREAT, DLESSDASH,
	CLOBBER,
};

enum				e_reserved_words
{
	If = CLOBBER + 1, Then, Else, Elif, Fi, Do, Done,
	Case, Esac, While, Until, For,
	Lbrace, Rbrace, Bang,
	In
};

typedef struct		s_token
{
	char 			*val;
	int				len;
	int				type;
}					t_token;

/* Hold the state of the lexer */
typedef struct		s_lex
{
	/* t_token			token; */
	/* int				started; */
	int				delimited;
	int				quoted;
	int				commented;
	char			*tknbeg;
	char			*tknend;
	int				tkntype;
}					t_lex;

typedef struct		s_item
{
	int				ind;
	char*			str;
}					t_item;

int		lex_rule_one(char *c, t_lex *status);
int		lex_rule_two(char *c, t_lex *status);
int		lex_rule_three(char *c, t_lex *status);
int		lex_rule_four(char *c, t_lex *status);
int		lex_rule_five(char *c, t_lex *status);
int		lex_rule_six(char *c, t_lex *status);
int		lex_rule_seven(char *c, t_lex *status);
int		lex_rule_eight(char *c, t_lex *status);
int		lex_rule_nine(char *c, t_lex *status);
int		lex_rule_ten(char *c, t_lex *status);

t_item				*operators(void);
int					compar_item_firstchar(const void *p1, const void *p2);
int					compar_item_str(const void *p1, const void *p2);
int					tkn_is_op(t_lex status);
t_item				*char_form_op(char *c, t_lex status);
#endif
