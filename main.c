#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int     main(int ac, char **av)
{
        if (ac != 4)
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
        int fd3 = open(av[3], O_RDONLY);
        if (fd3 == -1)
        {
                perror("open");
                return (42);
        }

	char    *line1 , *line2, *line3;
        size_t i = 1;
  
		printf("\n1---------------------------------\n\n\n\n");
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);

        printf("line from fd1:======|> |%s|",line1);
       	printf("line from fd2:======|> |%s|",line2);
        printf("line from fd3:======|> |%s|",line3);
		free(line1);
		free(line2);
		free(line3);
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);
		printf("\n---------------------------------\n\n\n\n");
		
		printf("line from fd1:======|> |%s|",line1);
		printf("line from fd2:======|> |%s|",line2);
        printf("line from fd3:======|> |%s|",line3);
		free(line1);
		free(line2);
		free(line3);
		printf("\n---------------------------------\n\n\n\n");
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);
		
		printf("line from fd1:======|> |%s|",line1);
		printf("line from fd2:======|> |%s|",line2);
        printf("line from fd3:======|> |%s|",line3);
		free(line1);
		free(line2);
		free(line3);
		printf("\n---------------------------------\n\n\n\n");
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);
		
		printf("line from fd1:======|> |%s|",line1);
		printf("line from fd2:======|> |%s|",line2);
        printf("line from fd3:======|> |%s|",line3);
		free(line1);
		free(line2);
		free(line3);
		printf("\n---------------------------------\n\n\n\n");
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);
		
		printf("line from fd1:======|> |%s|",line1);
		printf("line from fd2:======|> |%s|",line2);
        printf("line from fd3:======|> |%s|",line3);
		free(line1);
		free(line2);
		free(line3);
}
     
