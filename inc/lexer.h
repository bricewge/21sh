/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaegene <bwaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 19:24:35 by bwaegene          #+#    #+#             */
/*   Updated: 2017/12/06 17:16:32 by bwaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "libft.h"
# include "to_sh.h"

enum				e_rules
{
	NEXT = 0, APPLY
};

enum				e_states
{
	S_GENERAL = 0, S_QUOTE, S_OPERATOR, S_WORD
};

enum				e_words
{
	WORD = 1, ASSIGNMENT_WORD, NAME, NEWLINE, IO_NUMBER,
};

enum				e_operators
{
	ANDIF = IO_NUMBER + 1, ORIF, DSEMI,
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

typedef struct		s_tkn
{
	char 			*val;
	int				len;
	int				type;
}					t_tkn;

/* Hold the state of the lexer */
typedef struct		s_lex
{
	char			*curtkn_start;
	int				curtkn_len;
	int				curtkn_type;
	t_list			*tknlst_start;
	t_list			*tknlst_last;
}					t_lex;

typedef struct		s_item
{
	int				idx;
	char*			str;
}					t_item;

int		lex_rule_one(char **c, t_lex *status);
int		lex_rule_two(char **c, t_lex *status);
int		lex_rule_three(char **c, t_lex *status);
int		lex_rule_four(char **c, t_lex *status);
int		lex_rule_five(char **c, t_lex *status);
int		lex_rule_six(char **c, t_lex *status);
int		lex_rule_seven(char **c, t_lex *status);
int		lex_rule_eight(char **c, t_lex *status);
int		lex_rule_nine(char **c, t_lex *status);
int		lex_rule_ten(char **c, t_lex *status);

void	lex_delimit_tkn(t_lex *status);
char	*lex_scanner(char *path);

t_tkn	*tkn_alloc(char *val, int len, int type);
void	tkn_print(t_lex status, t_tkn tkn);
void	tknlst_append(t_tkn *tkn, t_lex *status);

t_item				*operators(void);
int					compar_item_firstchar(const void *p1, const void *p2);
int					compar_item_str(const void *p1, const void *p2);
int					tkn_is_op(t_lex status);
int					can_form_op(t_lex status);
#endif
