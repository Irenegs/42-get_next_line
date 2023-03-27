#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void print_file(int openfile)
{
	char *line;

	line = get_next_line(openfile);
	printf("\nLet's begin\n");
	while (line != NULL)
	{
		printf("[%s]", line);
		free(line);
		line = get_next_line(openfile);
	}
	free(line);
}


int	main(int argc, char **argv)
{
	int openfile;

	if (argc > 1)
	{
		char *file = argv[1];
		openfile = open(file, O_RDONLY);
	}
	else
	{
		openfile = 0;
	}
	print_file(openfile);
	if (openfile != 0){
	close(openfile);}
	return 0;
}
