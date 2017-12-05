#include "lexer.h"
#include "get_next_line.h"
#include <fcntl.h>

char	*lex_scanner(char *path)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open(path, O_RDONLY);
	get_next_line(fd, &line);
	/* close(fd); */
	return(line);
}
