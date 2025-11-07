#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int     main(int ac, char **av)
{
        if (ac != 2)
                return 42;

        int fd1 = open(av[1], O_RDONLY);
        if (fd1 == -1)
        {
                perror("open");
                return (42);
        }
	char    *line;
        size_t i = 1;
	while ((line = get_next_line(fd1)))
	{
       		printf("line fd1: %s", line);
       		free(line);
	}
}
     
