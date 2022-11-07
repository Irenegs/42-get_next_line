#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void print_file(char *file_name)
{
	char *line;
	int	i=0;
	int openfile;
	
	openfile = open(file_name, O_RDONLY);
	line = get_next_line(openfile);
	while (line != NULL && i < 10)	
	{
		printf("LINE: %s", line);
		free(line);
		line = get_next_line(openfile);
		i++;
	}
	close(openfile);
}


int	main(void)
{
	printf("file\n");
	print_file("file");
	/*printf("file1\n");
	print_file("file1");
	printf("file2\n");
	print_file("file2");
	printf("file3\n");
	print_file("file3");*/
}
