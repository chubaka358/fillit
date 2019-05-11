#include "fillit.h"

int     is_valid(int fd)
{
    char    *line[129];
    int     ret;
    int     i;

    i = 0;
    while ((ret = get_next_line(fd, &(line[i]))))
    {
        if (ret == -1)
            return (0);
    }
    return (1);
}

int     main(int argc, char **argv)
{
    int     fd;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (is_valid(fd))
        {
            
        }
        else
            write(1, "error\n", 6);
    }
    else
    {
        
    }
    return (0);
}