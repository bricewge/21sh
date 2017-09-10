#include "lexer.h"

s_char	lex_scanner(int fd)
{
	static s_char	c = {0, 0, 0, 0};
	int				ret;

	if (fd >= 0)
	{
		ret = read(fd, &c, 1);
		if (ret == 0)
			c.c = 0;
		else if (ret < 0)
			ft_puterror("read error", "", 1);
		if (newline)
		{
			c.line += 1;
			c.col = 0;
		}
		else
			c.col += 1;
		c.pos += 1;
		return (c);
	};
	else
		ft_puterror("wrong fd", "", 1);
}
