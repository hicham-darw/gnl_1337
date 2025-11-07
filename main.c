#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int     main(int ac, char **av)
{
        if (ac != 3)
                return 42;

        int fd1 = open(av[1], O_RDONLY);
        if (fd1 == -1)
        {
                perror("open");
                return (42);
        }
        int fd2= open(av[2], O_RDONLY);
        if (fd2 == -1)
        {
                perror("open");
                return (42);
        }

	char    *line1 , *line2;
        size_t i = 1;
  

	while ((line1 = get_next_line(fd1)))
	{
		while ((line2 = get_next_line(fd2)))
		{
        		printf("line from fd2:======|> %s*******\n",line2);
			free(line2);
			break;
		}
        	printf("*******\nline from fd1:======|>  %s",line1);
		free(line1);
	}
}
     
